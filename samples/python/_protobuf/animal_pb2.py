# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: animal.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='animal.proto',
  package='Animal',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=b'\n\x0c\x61nimal.proto\x12\x06\x41nimal\"#\n\x03\x44og\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x0e\n\x06\x63olour\x18\x02 \x01(\tb\x06proto3'
)




_DOG = _descriptor.Descriptor(
  name='Dog',
  full_name='Animal.Dog',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='Animal.Dog.name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='colour', full_name='Animal.Dog.colour', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=24,
  serialized_end=59,
)

DESCRIPTOR.message_types_by_name['Dog'] = _DOG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Dog = _reflection.GeneratedProtocolMessageType('Dog', (_message.Message,), {
  'DESCRIPTOR' : _DOG,
  '__module__' : 'animal_pb2'
  # @@protoc_insertion_point(class_scope:Animal.Dog)
  })
_sym_db.RegisterMessage(Dog)


# @@protoc_insertion_point(module_scope)
