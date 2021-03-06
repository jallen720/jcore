#include <cstring>
#include <sstream>
#include "cpp_utils/string.hpp"
#include "cpp_utils/validators.hpp"

using std::vector;
using std::stringstream;
using std::getline;

namespace cpp_utils
{

bool are_equal(const std::string & string, const char * c_string)
{
    return strcmp(string.c_str(), c_string) == 0;
}

bool are_equal(const char * c_string_a, const char * c_string_b)
{
    return strcmp(c_string_a, c_string_b) == 0;
}

bool is_empty(const char * c_string)
{
    validate_not_null("c_string", "is_empty", c_string);
    return strcmp(c_string, "") == 0;
}

vector<std::string> split(const std::string & string, const char delimiter)
{
    vector<std::string> elements;
    stringstream stream(string);
    std::string element;

    while (getline(stream, element, delimiter))
    {
        elements.push_back(element);
    }

    return elements;
}

template<>
std::string to_string(const bool value)
{
    return value == true ? "true" : "false";
}

} // namespace cpp_utils
