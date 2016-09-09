#include "CppUtils/FileUtils/readFile.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/TestUtils/assertNoThrow.hpp"
#include "CppUtils/TestUtils/validResourcePath.hpp"
#include "CppUtils/TestUtils/assertEqualElements.hpp"


using std::string;
using std::vector;
using std::runtime_error;


namespace CppUtils {


TEST(readFileTest, validCreation) {
    assertNoThrow([]() -> void {
        readFile(validResourcePath("misc", "test.txt"));
    });
}


TEST(readFileTest, invalidFile) {
    ASSERT_THROW(readFile("does_not_exist"), runtime_error);
}


TEST(readFileTest, emptyPath) {
    ASSERT_THROW(readFile(""), runtime_error);
}


TEST(readFileTest, contentMatch) {
    const string expectedContent =
        "line1\n"
        "line2\n"
        "line3\n";

    ASSERT_EQ(expectedContent, readFile(validResourcePath("misc", "test.txt")));
}


} // namespace CppUtils