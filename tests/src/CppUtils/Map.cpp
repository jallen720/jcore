#include "CppUtils/Map.hpp"

#include <string>
#include <gtest/gtest.h>

#include "CppUtils/Test.hpp"


using std::map;
using std::string;


namespace CppUtils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// contains_key() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(contains_key_Test, valid_map)
{
    const map<string, const string> valid_map
    {
        { "key0" , "value0" },
        { "key1" , "value1" },
        { "key2" , "value2" },
    };

    ASSERT_TRUE(contains_key(valid_map, string("key0")));
    ASSERT_TRUE(contains_key(valid_map, string("key1")));
    ASSERT_TRUE(contains_key(valid_map, string("key2")));
    ASSERT_FALSE(contains_key(valid_map, string("key3")));
    ASSERT_FALSE(contains_key(valid_map, string("value0")));
}


TEST(contains_key_Test, empty_map)
{
    const map<string, const string> empty_map;

    ASSERT_FALSE(contains_key(empty_map, string("key0")));
    ASSERT_FALSE(contains_key(empty_map, string("")));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// get_values() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(get_values_Test, valid_map)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_equal_elements({ 0, 1, 2 }, get_values(valid_map));
}


TEST(get_values_Test, empty_map)
{
    const map<string, const int> empty_map;
    assert_equal_elements({}, get_values(empty_map));
}


} // namespace CppUtils