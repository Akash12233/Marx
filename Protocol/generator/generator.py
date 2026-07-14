#!/usr/bin/env python3
"""
Entry point for the protocol header generator.

Usage:
    python3 generate.py                 # generate headers for every protocol under schema/
    python3 generate.py --protocol fix  # generate headers for just one protocol

Dependency order per protocol (hard requirement, do not reorder):
    enumerations.xml -> Enumerations.hpp
    fields.xml        -> Fields.hpp        (depends on parsed enums)
    payloads.xml      -> messages/*.hpp    (depends on parsed fields + enums)
"""

import argparse
import os
import sys

from jinja2 import Environment, FileSystemLoader

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from parsers.enum_parser import parse_enumerations
from parsers.field_parser import parse_fields
from parsers.message_parser import parse_messages

from parsers.enum_emitter import build_enum_context
from parsers.field_emitter import build_field_context
from parsers.message_emitter import build_message_context


GENERATOR_DIR = os.path.dirname(os.path.abspath(__file__))
PROTOCOL_ROOT = os.path.dirname(GENERATOR_DIR)          # .../protocol
SCHEMA_ROOT = os.path.join(PROTOCOL_ROOT, "schema")
INCLUDE_ROOT = os.path.join(PROTOCOL_ROOT, "include")
TEMPLATES_DIR = os.path.join(GENERATOR_DIR, "templates")

jinja_env = Environment(
    loader=FileSystemLoader(TEMPLATES_DIR),
    trim_blocks=True,
    lstrip_blocks=True,
    keep_trailing_newline=True,
)


def discover_protocols() -> list:
    """
    Every subdirectory of schema/ that has all 3 required XML files, each
    containing valid, non-empty XML, is treated as a protocol. Anything
    else is skipped with a warning rather than crashing the whole run.
    """
    import xml.etree.ElementTree as ET

    if not os.path.isdir(SCHEMA_ROOT):
        return []

    required_files = ["enumerations.xml", "fields.xml", "payloads.xml"]
    protocols = []

    for name in sorted(os.listdir(SCHEMA_ROOT)):
        proto_dir = os.path.join(SCHEMA_ROOT, name)
        if not os.path.isdir(proto_dir):
            continue

        missing = []
        invalid = []
        for fname in required_files:
            fpath = os.path.join(proto_dir, fname)
            if not os.path.isfile(fpath):
                missing.append(fname)
                continue
            try:
                root = ET.parse(fpath).getroot()
                if len(root) == 0:
                    invalid.append(f"{fname} (no child elements)")
            except ET.ParseError:
                invalid.append(f"{fname} (not valid XML)")

        if missing:
            print(f"[{name}] skipping - missing {', '.join(missing)}")
            continue
        if invalid:
            print(f"[{name}] skipping - {', '.join(invalid)}")
            continue

        protocols.append(name)

    return protocols

def generate_protocol(protocol: str) -> None:
    print(f"[{protocol}] generating...")
    schema_dir = os.path.join(SCHEMA_ROOT, protocol)
    include_dir = os.path.join(INCLUDE_ROOT, protocol)

    enum_xml = os.path.join(schema_dir, "enumerations.xml")
    fields_xml = os.path.join(schema_dir, "fields.xml")
    payloads_xml = os.path.join(schema_dir, "payloads.xml")

    for required_file in (enum_xml, fields_xml, payloads_xml):
        if not os.path.isfile(required_file):
            raise FileNotFoundError(f"[{protocol}] missing required schema file: {required_file}")

    # ---- Stage 1: Enumerations -------------------------------------------
    enums = parse_enumerations(enum_xml)
    enum_by_name = {e.name: e for e in enums}

    enum_ctx = build_enum_context(enums, protocol)
    enum_out_dir = os.path.join(include_dir, "enumerations")
    os.makedirs(enum_out_dir, exist_ok=True)
    _render_to_file("enumerations.hpp.j2", enum_ctx, os.path.join(enum_out_dir, "Enumerations.hpp"))
    print(f"[{protocol}]   Enumerations.hpp  ({len(enums)} enums)")

    # ---- Stage 2: Fields ----------------------------------------------
    fields = parse_fields(fields_xml, enum_by_name)
    field_by_name = {f.name: f for f in fields}

    field_ctx = build_field_context(fields, enum_by_name, protocol)
    fields_out_dir = os.path.join(include_dir, "fields")
    os.makedirs(fields_out_dir, exist_ok=True)
    _render_to_file("fields.hpp.j2", field_ctx, os.path.join(fields_out_dir, "Fields.hpp"))
    print(f"[{protocol}]   Fields.hpp        ({len(fields)} fields)")

    # ---- Stage 3: Messages ----------------------------------------------
    messages = parse_messages(payloads_xml, field_by_name)
    messages_out_dir = os.path.join(include_dir, "messages")
    os.makedirs(messages_out_dir, exist_ok=True)
    for msg in messages:
        msg_ctx = build_message_context(msg, field_by_name, enum_by_name, protocol)
        out_path = os.path.join(messages_out_dir, f"{msg.name}.hpp")
        _render_to_file("message.hpp.j2", msg_ctx, out_path)
    print(f"[{protocol}]   messages/*.hpp    ({len(messages)} messages)")


def _render_to_file(template_name: str, context: dict, out_path: str) -> None:
    template = jinja_env.get_template(template_name)
    rendered = template.render(**context)
    with open(out_path, "w") as f:
        f.write(rendered)


def main():
    parser = argparse.ArgumentParser(description="Generate C++ protocol headers from XML schema.")
    parser.add_argument("--protocol", help="Generate only this protocol (default: all under schema/)")
    args = parser.parse_args()

    protocols = [args.protocol] if args.protocol else discover_protocols()

    if not protocols:
        print(f"No protocols found under {SCHEMA_ROOT}")
        sys.exit(1)

    for protocol in protocols:
        generate_protocol(protocol)

    print("Done.")


if __name__ == "__main__":
    main()