# @generated
# To regenerate `fbcode/thrift/test/gen_if`, invoke
#   `buck run //thrift/test:generate_thrift_files`


namespace cpp2 apache.thrift.test

struct struct_required_map_string_i64_cpp_ref {
  1: required map<string, i64> (cpp.ref = 'true') field_1;
  2: required map<string, i64> (cpp.ref = 'true') field_2;
}
