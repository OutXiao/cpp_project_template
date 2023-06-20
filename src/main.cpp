#include <iostream>
#include <vector>
#include <string>
#include "stringutil.h"
using namespace std;

#include <gtest/gtest.h>

TEST(stringutil, toLowerUpper)
{
  string str = "AbcdEfg";
  string lowerTarget = "abcdefg";
  string upperTarget = "ABCDEFG";
  EXPECT_EQ(StringUtil::toLower(str), lowerTarget);
  EXPECT_EQ(StringUtil::toUpper(str), upperTarget);
}
TEST(stringutil, removeChars)
{
  string str = "   AbcdEfg123 1111 12333 123;;;\n\n\n\t\tuuuuuii";
  string target = "AbcdEfg123111112333123uuuuuii";
  EXPECT_EQ(StringUtil::removeChars(str, " \t\n;;:"), target);
}
TEST(stringutil, join)
{
  vector<std::string> v = {"123","456","123","456","123","456","123","456","123","456","123","456"};
  std::string target;
  std::string limiter = "UU";
  for(auto& str : v)
  {
    target += str + limiter;
  }
  target = target.substr(0, target.size()-2);
  EXPECT_EQ(StringUtil::join(v, limiter), target);
}

TEST(stringutil, replace)
{
  string str = "   AbcdEfg123 1111 12333 123;;;\n\n\n\t\tuuuuuii";
  string target = "AbcdEfg123111112333123;;;\n\n\n\t\tuuuuuii";
  EXPECT_EQ(StringUtil::replace(str, " ", ""), target);
}




TEST(StringUtilTest, trim) {
    string str = "  Hello, World!  \t";
    string target = "Hello, World!";
    // Test leading and trailing spaces
    EXPECT_EQ(StringUtil::trim(str), target);
    str = "  Hello, World!";
    target = "Hello, World!";
    // Test leading spaces only
    EXPECT_EQ(StringUtil::trim(str), target);
    str = "Hello, World!  ";
    target = "Hello, World!";
    // Test trailing spaces only
    EXPECT_EQ(StringUtil::trim(str), target);

    str = "Hello, World!";
    target = "Hello, World!";
    // Test no spaces
    EXPECT_EQ(StringUtil::trim(str), target);
    str = "";
    target = "";
    // Test empty string
    EXPECT_EQ(StringUtil::trim(str), target);
    str = "     ";
    target = "";
    // Test string with only spaces
    EXPECT_EQ(StringUtil::trim(str), target);
}

TEST(StringUtilTest, trimLeft) {
    string str = "  Hello";
    string target = "Hello";
    // Test trimming leading spaces
    EXPECT_EQ(StringUtil::trimLeft(str), target);
    str = "Hello";
    target = "Hello";
    // Test no leading spaces
    EXPECT_EQ(StringUtil::trimLeft(str), target);
    str = "    ";
    target = "";
    // Test trimming only spaces
    EXPECT_EQ(StringUtil::trimLeft(str), target);
    str = "";
    target = "";
    // Test trimming empty string
    EXPECT_EQ(StringUtil::trimLeft(str), target);
}

TEST(StringUtilTest, trimRight) {
    string str = "Hello  ";
    string target = "Hello";
    // Test trimming trailing spaces
    EXPECT_EQ(StringUtil::trimRight(str), target);
    str = "Hello  ";
    target = "Hello";
    // Test no trailing spaces
    EXPECT_EQ(StringUtil::trimRight(str), target);
    str = "    ";
    target = "";
    // Test trimming only spaces
    EXPECT_EQ(StringUtil::trimLeft(str), target);
    str = "";
    target = "";
    // Test trimming empty string
    EXPECT_EQ(StringUtil::trimLeft(str), target);
}

TEST(StringUtilTest, startsWith) {
    string str = "Hello World";
    string target = "Hello";
    // Test string starts with the same string
    EXPECT_TRUE(StringUtil::startsWith("Hello World", "Hello"));

    str = "Hello World";
    target = "World";
    // Test string starts with a different string
    EXPECT_FALSE(StringUtil::startsWith(str, target));
    
    // Test empty string
    EXPECT_FALSE(StringUtil::startsWith("", "Hello"));

    // Test empty prefix
    EXPECT_TRUE(StringUtil::startsWith("Hello World", ""));
}

TEST(StringUtilTest, match) {
    // Test matching pattern
    EXPECT_TRUE(StringUtil::match("Hello World", std::regex("Hello.*")));

    // Test non-matching pattern
    EXPECT_FALSE(StringUtil::match("Hello World", std::regex("Hi.*")));

    // Test empty string
    EXPECT_FALSE(StringUtil::match("", std::regex("Hello.*")));

    // Test empty pattern
    EXPECT_FALSE(StringUtil::match("Hello World", std::regex("")));
}

TEST(StringUtilTest, toInt) {
    // Test valid integer string
    EXPECT_EQ(StringUtil::toInt("123"), 123);

    // Test negative integer string
    EXPECT_EQ(StringUtil::toInt("-456"), -456);

    // Test invalid integer string
    //EXPECT_THROW(StringUtil::toInt("abc"), std::invalid_argument);

    // Test empty string
    //EXPECT_THROW(StringUtil::toInt(""), std::invalid_argument);
}

TEST(StringUtilTest, toLong) {
    // Test valid long string
    EXPECT_EQ(StringUtil::toLong("1234567890"), 1234567890L);

    // Test negative long string
    EXPECT_EQ(StringUtil::toLong("-9876543210"), -9876543210L);

    // Test invalid long string
    //EXPECT_THROW(StringUtil::toLong("abc"), std::invalid_argument);

    // Test empty string
    //EXPECT_THROW(StringUtil::toLong(""), std::invalid_argument);
}

TEST(StringUtilTest, toFloat) {
    // Test valid float string
    EXPECT_FLOAT_EQ(StringUtil::toFloat("3.14"), 3.14f);

    // Test negative float string
    EXPECT_FLOAT_EQ(StringUtil::toFloat("-2.5"), -2.5f);

    // Test invalid float string
    //EXPECT_THROW(StringUtil::toFloat("abc"), std::invalid_argument);

    // Test empty string
    //EXPECT_THROW(StringUtil::toFloat(""), std::invalid_argument);
}

TEST(StringUtilTest, toDouble) {
    // Test valid double string
    EXPECT_DOUBLE_EQ(StringUtil::toDouble("3.14159"), 3.14159);

    // Test negative double string
    EXPECT_DOUBLE_EQ(StringUtil::toDouble("-2.71828"), -2.71828);

    // Test invalid double string
    //EXPECT_THROW(StringUtil::toDouble("abc"), std::invalid_argument);

    // Test empty string
    //EXPECT_THROW(StringUtil::toDouble(""), std::invalid_argument);
}

// Test case for countChars function
TEST(StringUtilTest, CountCharsTest) {
    std::string input = "Hello, World!";
    size_t expected = 10;
    size_t result = StringUtil::countChars(input);
    ASSERT_EQ(result, expected);
}
// Test case for substring function with start parameter
TEST(StringUtilTest, SubstringStartTest) {
    std::string input = "Hello, World!";
    size_t start = 7;
    std::string expected = "World!";
    std::string result = StringUtil::substring(input, start);
    ASSERT_EQ(result, expected);
}
// Test case for substring function with start and length parameters
TEST(StringUtilTest, SubstringStartLengthTest) {
    std::string input = "Hello, World!";
    size_t start = 7;
    size_t length = 5;
    std::string expected = "World";

    std::string result = StringUtil::substring(input, start, length);

    ASSERT_EQ(result, expected);
}

// Test case for reverse function
TEST(StringUtilTest, ReverseTest) {
    std::string input = "Hello, World!";
    std::string expected = "!dlroW ,olleH";

    std::string result = StringUtil::reverse(input);

    ASSERT_EQ(result, expected);
}

// Test case for padLeft function
TEST(StringUtilTest, PadLeftTest) {
    std::string input = "Hello";
    size_t totalWidth = 10;
    char paddingChar = '-';
    std::string expected = "-----Hello";
    std::string result = StringUtil::padLeft(input, totalWidth, paddingChar);
    ASSERT_EQ(result, expected);
}

// Test case for padRight function
TEST(StringUtilTest, PadRightTest) {
    std::string input = "Hello";
    size_t totalWidth = 10;
    char paddingChar = '-';
    std::string expected = "Hello-----";
    std::string result = StringUtil::padRight(input, totalWidth, paddingChar);
    ASSERT_EQ(result, expected);
}

// Test case for removeChars function
TEST(StringUtilTest, removeChars) {
    
    char* result = StringUtil::removeChars("123 123 12", " ");
    const char* expected = "12312312";
    string str = result;
    string str1 = expected;
    ASSERT_EQ(str.compare(str1), 0);
}

// Test case for padRight function
TEST(StringUtilTest, join) {
    const char* strs[2] = {"123", "3445"};
    const char* delimiter = "--";
    const char** str = strs;
    char* result = StringUtil::join(str, 2, delimiter);
    const char* expected = "123--3445";
    string str2 = result;
    string str3 = expected;
    ASSERT_EQ(str2.compare(str3), 0);
}

// Test case for replace function
TEST(StringUtilTest, replace) {
    const char* str = "123  123  123";
    const char* target = " ";
    const char* replacement = "+";
    string str2 = StringUtil::replace(str, target, replacement);
    string str3 = "123++123++123";
    ASSERT_EQ(str2.compare(str3), 0);
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
