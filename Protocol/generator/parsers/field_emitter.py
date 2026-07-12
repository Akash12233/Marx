"""
Turns list[models.Field] into Fields.hpp text via the Jinja2 template.
"""


def _to_string_data_expr(field, enum_by_name: dict) -> str:
    """
    Only relevant for enum-backed fields: how to render the raw wire value
    as a string. char -> single-char string, numeric -> std::to_string.
    """
    enum_def = enum_by_name[field.type]
    if enum_def.raw_type == "char":
        return "std::string(1, value_)"
    return "std::to_string(value_)"


def build_field_context(fields: list, enum_by_name: dict, protocol: str) -> dict:
    """Returns the dict passed straight into the fields.hpp.j2 template."""
    field_ctx = []
    for f in fields:
        if f.is_enum:
            kind = "enum"
        elif f.cpp_type == "std::string":
            kind = "string"
        else:
            kind = "primitive"

        entry = {
            "name": f.name,
            "type": f.type,          # only meaningful for kind == "enum" (enum name)
            "cpp_type": f.cpp_type,
            "kind": kind,
            "tag" : f.tag
        }
        if kind == "enum":
            entry["to_string_data_expr"] = _to_string_data_expr(f, enum_by_name)

        field_ctx.append(entry)

    return {"protocol": protocol, "fields": field_ctx}