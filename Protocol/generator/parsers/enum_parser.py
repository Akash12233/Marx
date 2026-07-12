"""
Parses <protocol>/enumerations.xml into a list of models.Enum.

No dependency on any other schema file - Enumerations is the root of the
generation dependency chain (Enumerations -> Fields -> Messages).
"""

import xml.etree.ElementTree as ET
import sys
import os

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from models import Enum, EnumValue


def parse_enumerations(xml_path: str) -> list:
    """Returns list[Enum]."""
    tree = ET.parse(xml_path)
    root = tree.getroot()

    enums = []
    for enum_el in root.findall("Enum"):
        name = enum_el.get("name")
        raw_type = enum_el.get("type")

        if not name:
            raise ValueError(f"<Enum> missing required 'name' attribute in {xml_path}")
        if not raw_type:
            raise ValueError(f"<Enum name='{name}'> missing required 'type' attribute in {xml_path}")

        values = []
        for value_el in enum_el.findall("Value"):
            v_name = value_el.get("name")
            v_raw = value_el.get("raw")
            if not v_name or v_raw is None:
                raise ValueError(f"<Value> under Enum '{name}' needs 'name' and 'raw' attributes")
            values.append(EnumValue(name=v_name, raw=v_raw))

        if not values:
            raise ValueError(f"Enum '{name}' has no <Value> entries")

        enums.append(Enum(name=name, raw_type=raw_type, values=values))

    return enums