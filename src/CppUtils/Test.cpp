#include "CppUtils/Test.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>

#include "CppUtils/File.hpp"


using std::cerr;
using std::exception;
using std::function;
using std::string;


namespace CppUtils
{


static const string TESTS_RESOURCES_DIRECTORY = "tests/resources/";


void assert_no_throw(const function<void()> & block)
{
    try
    {
        block();
    }
    catch (const exception & error)
    {
        cerr << "std::exception thrown in test:\n  " << error.what() << "\n";
        FAIL();
    }
    catch (...)
    {
        cerr << "Unknown exception thrown in test!\n";
        FAIL();
    }
}


string invalid_resource_path(const string & sub_directory, const string & name)
{
    return TESTS_RESOURCES_DIRECTORY + "invalid/" + directify(sub_directory) + name;
}


string valid_resource_path(const string & sub_directory, const string & name)
{
    return TESTS_RESOURCES_DIRECTORY + "valid/" + directify(sub_directory) + name;
}


} // namespace CppUtils
