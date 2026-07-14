"""
Turns a single models.Message (plus lookups into fields/enums) into the
context dict for message.hpp.j2. One of these runs per <Message>.
"""


def _member_name(field_name: str) -> str:
    """ClOrdID -> clOrdID (lower-camelCase member name)."""
    if not field_name:
        return field_name
    return field_name[0].lower() + field_name[1:]


def _resolve_default_init_expr(field_ref, field_def, enum_by_name: dict) -> str:
    """
    Resolves a MessageFieldRef.default_value into the literal passed to the
    field's constructor at brace-init, e.g. `'1'` for an enum default, or
    `"XYZ"` for a string default, or `100` for a numeric default.
    Returns None if there's no default to apply.
    """
    if field_ref.default_value is None:
        return None

    if field_def.is_enum:
        enum_def = enum_by_name[field_def.type]
        match = next((v for v in enum_def.values if v.name == field_ref.default_value), None)
        if match is None:
            raise ValueError(
                f"defaultValue '{field_ref.default_value}' on field '{field_ref.name}' "
                f"is not a valid value of enum '{field_def.type}'"
            )
        return f"'{match.raw}'" if enum_def.raw_type == "char" else match.raw

    if field_def.cpp_type == "std::string":
        return f"\"{field_ref.default_value}\""

    # numeric primitive default - passed through as-is
    return field_ref.default_value


def build_message_context(message, field_by_name: dict, enum_by_name: dict, protocol: str) -> dict:
    """Returns the dict passed straight into the message.hpp.j2 template."""
    field_ref_ctx = []
    for fr in message.field_refs:
        field_def = field_by_name[fr.name]
        field_ref_ctx.append({
            "name": fr.name,
            "member_name": _member_name(fr.name),
            "required": fr.required,
            "init_expr": _resolve_default_init_expr(fr, field_def, enum_by_name),
        })

    return {
        "protocol": protocol,
        "message": {"name": message.name, "field_refs": field_ref_ctx},
    }