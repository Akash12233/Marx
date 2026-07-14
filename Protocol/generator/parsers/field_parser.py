"""
Parses <protocol>/fields.xml into a list of models.Field.

Depends on the already-parsed Enum list (from enum_parser) to resolve
whether a given `type=` attribute is an enum reference or a primitive.
This encodes the hard dependency: Enumerations must be parsed before Fields.
"""

import xml.etree.ElementTree as ET
import sys
import os

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from models import Field
from type_map import resolve_primitive


def parse_fields(xml_path: str, known_enums: dict) -> list:
    """
    known_enums: dict[str, models.Enum] - name -> Enum, from enum_parser output.
    Returns list[Field].
    """
    tree = ET.parse(xml_path)
    root = tree.getroot()

    fields = []
    for field_el in root.findall("Field"):
        name = field_el.get("name")
        type_name = field_el.get("type")
        tag_attr = field_el.get("tag")


        if not name:
            raise ValueError(f"<Field> missing required 'name' attribute in {xml_path}")
        if not type_name:
            raise ValueError(f"<Field name='{name}'> missing required 'type' attribute in {xml_path}")

        if type_name in known_enums:
            # Enum-backed field: raw storage type is inherited from the enum's own type.
            enum_def = known_enums[type_name]
            cpp_raw_type = resolve_primitive(enum_def.raw_type)
            if cpp_raw_type is None:
                raise ValueError(
                    f"Enum '{type_name}' declares unknown raw type '{enum_def.raw_type}'"
                )
            fields.append(Field(
                name=name,
                type=type_name,
                is_enum=True,
                enum_raw_type=cpp_raw_type,
                cpp_type=cpp_raw_type,
            ))
        else:
            # Plain primitive field.
            cpp_type = resolve_primitive(type_name)
            if cpp_type is None:
                raise ValueError(
                    f"Field '{name}' has type '{type_name}' which is neither a known "
                    f"enum nor a known primitive. Check enumerations.xml / type_map.py."
                )
            fields.append(Field(
                name=name,
                type=type_name,
                is_enum=False,
                cpp_type=cpp_type,
            ))
        tag = int(tag_attr) if tag_attr is not None else None


    return fields