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

#include <folly/portability/GTest.h>
#include <thrift/lib/cpp2/BadFieldAccess.h>
#include <thrift/test/gen-cpp2/UnionFieldRef_types.h>
using namespace std;

namespace apache {
namespace thrift {
namespace test {

TEST(UnionFieldTest, basic) {
  Basic a;

  EXPECT_EQ(a.getType(), Basic::__EMPTY__);
  EXPECT_FALSE(a.int64_ref());
  EXPECT_THROW(a.int64_ref().value(), bad_field_access);
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_FALSE(a.str_ref());
  EXPECT_THROW(a.str_ref().value(), bad_field_access);

  const int64_t int64 = 42LL << 42;
  a.int64_ref() = int64;
  EXPECT_EQ(a.getType(), Basic::int64);
  EXPECT_TRUE(a.int64_ref());
  EXPECT_EQ(a.int64_ref().value(), int64);
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_FALSE(a.str_ref());
  EXPECT_THROW(a.str_ref().value(), bad_field_access);

  const vector<int32_t> list_i32 = {3, 1, 2};
  a.list_i32_ref() = list_i32;
  EXPECT_EQ(a.getType(), Basic::list_i32);
  EXPECT_FALSE(a.int64_ref());
  EXPECT_THROW(a.int64_ref().value(), bad_field_access);
  EXPECT_TRUE(a.list_i32_ref());
  EXPECT_EQ(a.list_i32_ref().value(), list_i32);
  EXPECT_FALSE(a.str_ref());
  EXPECT_THROW(a.str_ref().value(), bad_field_access);

  const string str = "foo";
  a.str_ref() = str;
  EXPECT_EQ(a.getType(), Basic::str);
  EXPECT_FALSE(a.int64_ref());
  EXPECT_THROW(a.int64_ref().value(), bad_field_access);
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_TRUE(a.str_ref());
  EXPECT_EQ(a.str_ref().value(), str);
}

TEST(UnionFieldTest, operator_deref) {
  Basic a;
  EXPECT_THROW(*a.int64_ref(), bad_field_access);
  EXPECT_THROW(*a.str_ref(), bad_field_access);
  a.int64_ref() = 42;
  EXPECT_EQ(*a.int64_ref(), 42);
  EXPECT_THROW(*a.str_ref(), bad_field_access);
  a.str_ref() = "foo";
  EXPECT_EQ(*a.str_ref(), "foo");
  EXPECT_THROW(*a.int64_ref(), bad_field_access);
}

TEST(UnionFieldTest, duplicate_type) {
  DuplicateType a;

  EXPECT_EQ(a.getType(), DuplicateType::__EMPTY__);
  EXPECT_FALSE(a.str1_ref());
  EXPECT_THROW(a.str1_ref().value(), bad_field_access);
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_FALSE(a.str2_ref());
  EXPECT_THROW(a.str2_ref().value(), bad_field_access);

  a.str1_ref() = string(1000, '1');
  EXPECT_EQ(a.getType(), DuplicateType::str1);
  EXPECT_TRUE(a.str1_ref());
  EXPECT_EQ(a.str1_ref().value(), string(1000, '1'));
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_FALSE(a.str2_ref());
  EXPECT_THROW(a.str2_ref().value(), bad_field_access);

  a.list_i32_ref() = vector<int32_t>(1000, 2);
  EXPECT_EQ(a.getType(), DuplicateType::list_i32);
  EXPECT_FALSE(a.str1_ref());
  EXPECT_THROW(a.str1_ref().value(), bad_field_access);
  EXPECT_TRUE(a.list_i32_ref());
  EXPECT_EQ(a.list_i32_ref().value(), vector<int32_t>(1000, 2));
  EXPECT_FALSE(a.str2_ref());
  EXPECT_THROW(a.str2_ref().value(), bad_field_access);

  a.str2_ref() = string(1000, '3');
  EXPECT_EQ(a.getType(), DuplicateType::str2);
  EXPECT_FALSE(a.str1_ref());
  EXPECT_THROW(a.str1_ref().value(), bad_field_access);
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_TRUE(a.str2_ref());
  EXPECT_EQ(a.str2_ref().value(), string(1000, '3'));

  a.str1_ref() = string(1000, '4');
  EXPECT_EQ(a.getType(), DuplicateType::str1);
  EXPECT_TRUE(a.str1_ref());
  EXPECT_EQ(a.str1_ref().value(), string(1000, '4'));
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_FALSE(a.str2_ref());
  EXPECT_THROW(a.str2_ref().value(), bad_field_access);

  a.str1_ref() = string(1000, '5');
  EXPECT_EQ(a.getType(), DuplicateType::str1);
  EXPECT_TRUE(a.str1_ref());
  EXPECT_EQ(a.str1_ref().value(), string(1000, '5'));
  EXPECT_FALSE(a.list_i32_ref());
  EXPECT_THROW(a.list_i32_ref().value(), bad_field_access);
  EXPECT_FALSE(a.str2_ref());
  EXPECT_THROW(a.str2_ref().value(), bad_field_access);
}
} // namespace test
} // namespace thrift
} // namespace apache
