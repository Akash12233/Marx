"""
Parses <protocol>/payloads.xml into a list of models.Message.

Depends on the already-parsed Field list (from field_parser) purely for
validation - every <Field name="..."> reference inside a <Message> must
exist in fields.xml, or we fail fast at generation time instead of at
C++ compile time.
"""

import xml.etree.ElementTree as ET
import sys
import os

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from models import Message, MessageFieldRef


def parse_messages(xml_path: str, known_fields: dict) -> list:
    """
    known_fields: dict[str, models.Field] - name -> Field, from field_parser output.
    Returns list[Message].
    """
    tree = ET.parse(xml_path)
    root = tree.getroot()

    messages = []
    for msg_el in root.findall("Message"):
        msg_name = msg_el.get("name")
        if not msg_name:
            raise ValueError(f"<Message> missing required 'name' attribute in {xml_path}")

        field_refs = []
        for field_el in msg_el.findall("Field"):
            f_name = field_el.get("name")
            if not f_name:
                raise ValueError(f"<Field> under Message '{msg_name}' missing 'name' attribute")
            if f_name not in known_fields:
                raise ValueError(
                    f"Message '{msg_name}' references field '{f_name}' which is not "
                    f"defined in fields.xml"
                )

            required = field_el.get("required", "false").lower() == "true"
            default_value = field_el.get("defaultValue")  # None if absent

            field_refs.append(MessageFieldRef(
                name=f_name,
                required=required,
                default_value=default_value,
            ))

        if not field_refs:
            raise ValueError(f"Message '{msg_name}' has no <Field> entries")

        messages.append(Message(name=msg_name, field_refs=field_refs))

    return messages