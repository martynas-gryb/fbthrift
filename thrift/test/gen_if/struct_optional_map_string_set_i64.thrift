# @generated
# To regenerate `fbcode/thrift/test/gen_if`, invoke
#   `buck run //thrift/test:generate_thrift_files`


namespace cpp2 apache.thrift.test

struct struct_optional_map_string_set_i64 {
  1: optional map<string, set<i64>> field_1;
  2: optional map<string, set<i64>> field_2;
}
