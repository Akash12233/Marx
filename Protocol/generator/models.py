"""
Shared in-memory model classes.

Parsers turn XML into these. Emitters turn these into C++ header text.
Keeping this layer in between means parsers/emitters never need to know
about each other directly.
"""

from dataclasses import dataclass, field


# ---------------------------------------------------------------------------
# Enumerations
# ---------------------------------------------------------------------------

@dataclass
class EnumValue:
    name: str   # e.g. "Buy"
    raw: str    # e.g. "1"  (still a string here; emitter casts per raw_type)


@dataclass
class Enum:
    name: str        # e.g. "Side"
    raw_type: str     # e.g. "char", "int32"
    values: list = field(default_factory=list)  # list[EnumValue]


# ---------------------------------------------------------------------------
# Fields
# ---------------------------------------------------------------------------

@dataclass
class Field:
    name: str          # e.g. "Price"
    type: str          # raw `type=` attribute from XML, e.g. "double" or "Side"
    is_enum: bool = False        # resolved by field_parser against known enum names
    enum_raw_type: str = None    # only set when is_enum: the underlying wire type
    cpp_type: str = None         # resolved C++ type for storage (primitive or enum's raw_type)
    tag: int = None          # FIX-style wire tag number; None if protocol doesn't use tags


# ---------------------------------------------------------------------------
# Messages
# ---------------------------------------------------------------------------

@dataclass
class MessageFieldRef:
    name: str                  # references a Field by name
    required: bool = False
    default_value: str = None  # raw string from XML; resolved against enum values if needed


@dataclass
class Message:
    name: str
    field_refs: list = field(default_factory=list)  # list[MessageFieldRef]