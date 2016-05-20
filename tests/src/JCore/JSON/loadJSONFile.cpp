#include "JCore/JSON/loadJSONFile.hpp"

#include <gtest/gtest.h>

#include "JCore/TestUtils/assertNoThrow.hpp"
#include "JCore/TestUtils/validResourcePath.hpp"
#include "JCore/TestUtils/invalidResourcePath.hpp"
#include "JCore/Errors/FileError.hpp"
#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"


namespace JCore {


TEST(loadJSONFileTest, loadValidFile) {
    assertNoThrow([]() -> void {
        loadJSONFile(validResourcePath("json", "testConfig.json"));
    });
}


TEST(loadJSONFileTest, emptyPath) {
    ASSERT_THROW(loadJSONFile(""), EmptyStringArg);
}


TEST(loadJSONFileTest, emptyFile) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "empty.json")), FileError);
}


TEST(loadJSONFileTest, parseError) {
    ASSERT_THROW(loadJSONFile(invalidResourcePath("json", "parseError.json")), FileError);
}


} // namespace JCore