/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

include "thrift/conformance/if/any.thrift"

cpp_include "<folly/io/IOBuf.h>"

namespace cpp2 apache.thrift.conformance
namespace php apache_thrift
namespace py thrift.conformance.object
namespace py.asyncio thrift_asyncio.conformance.object
namespace py3 thrift.conformance
namespace java.swift org.apache.thrift.conformance
namespace go thrift.conformance.object

// A dynamic struct/union/exception (e.g. a JSON Object).
struct Object {
  // The type of the object, if applicable.
  1: string type;

  // The members of the object.
  2: map<string, Value> members;
} (any_type.name = "facebook.com/thrift/Object")

// A dynamic value.
union Value {
  // Integers.
  2: bool boolValue;
  3: byte byteValue;
  4: i16 i16Value;
  5: i32 i32Value;
  6: i64 i64Value;

  // Floats.
  7: float floatValue;
  8: double doubleValue;

  // Strings.
  9: string stringValue;
  10: binary (cpp.type = "folly::IOBuf") binaryValue;

  // Containers of values.
  11: list<Value> listValue;
  12: map<Value, Value> mapValue;
  13: set<Value> setValue;

  // A dynamic object value.
  14: Object objectValue;

  // A static object value.
  15: any.Any anyValue;
} (any_type.name = "facebook.com/thrift/Value")

// An enumeration of all base types in thrift.
//
// Base types are unparametarized. For example, the base
// type of map<int, string> is BaseType::Map and the base type of
// all thrift structs is BaseType::Struct.
//
// Similar to lib/cpp/protocol/TType.h, but IDL
// concepts instead of protocol concepts.
enum BaseType {
  Void = 0,

  // Integral primitive types.
  Bool = 1,
  Byte = 2,
  I16 = 3,
  I32 = 4,
  I64 = 5,

  // Floating point primitive types.
  Float = 6,
  Double = 7,

  // Enum type classes.
  Enum = 8,

  // String primitive types.
  String = 9,
  Binary = 10,

  // Structured type classes.
  Struct = 11,
  Union = 12,
  Exception = 13,

  // Container type classes.
  List = 14,
  Set = 15,
  Map = 16,
}
