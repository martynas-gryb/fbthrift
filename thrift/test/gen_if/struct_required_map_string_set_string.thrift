# @generated
# To regenerate `fbcode/thrift/test/gen_if`, invoke
#   `buck run //thrift/test:generate_thrift_files`


namespace cpp2 apache.thrift.test

struct struct_required_map_string_set_string {
  1: required map<string, set<string>> field_1;
  2: required map<string, set<string>> field_2;
}
