"""
Maps schema-level primitive type names (used in fields.xml / enumerations.xml
`type=` attributes) to actual C++ types.

Extend this dict as new primitive types are needed - it's the single place
that controls what's a valid primitive `type=` value in the schema.
"""

PRIMITIVE_TYPE_MAP = {
    "string":  "std::string",
    "char":    "char",
    "int8":    "std::int8_t",
    "uint8":   "std::uint8_t",
    "int32":   "std::int32_t",
    "uint32":  "std::uint32_t",
    "int64":   "std::int64_t",
    "uint64":  "std::uint64_t",
    "long":    "std::int64_t",
    "double":  "double",
    "bool":    "bool",
}


def resolve_primitive(type_name: str) -> str:
    """Returns the C++ type for a known primitive, or None if unknown."""
    return PRIMITIVE_TYPE_MAP.get(type_name)