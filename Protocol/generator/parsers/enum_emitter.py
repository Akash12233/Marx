"""
Turns list[models.Enum] into Enumerations.hpp text via the Jinja2 template.
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from type_map import resolve_primitive


def _raw_literal(raw_value: str, raw_type: str) -> str:
    """Formats an EnumValue.raw string as a C++ literal appropriate to raw_type."""
    if raw_type == "char":
        return f"'{raw_value}'"
    # numeric types (int8/int32/uint32/int64/etc.) - bare literal is fine
    return raw_value


def build_enum_context(enums: list, protocol: str) -> dict:
    """Returns the dict passed straight into the enumerations.hpp.j2 template."""
    enum_ctx = []
    for e in enums:
        raw_cpp_type = resolve_primitive(e.raw_type)
        if raw_cpp_type is None:
            raise ValueError(f"Enum '{e.name}' has unknown raw type '{e.raw_type}'")

        value_ctx = [
            {"name": v.name, "raw_literal": _raw_literal(v.raw, e.raw_type)}
            for v in e.values
        ]

        enum_ctx.append({
            "name": e.name,
            "raw_cpp_type": raw_cpp_type,
            "enum_values": value_ctx,  # named to avoid colliding with dict.values() in Jinja dot-access
        })

    return {"protocol": protocol, "enums": enum_ctx}