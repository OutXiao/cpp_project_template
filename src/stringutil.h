#ifndef __STRING_UTIL_HEADER__
#define __STRING_UTIL_HEADER__
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <regex>

class StringUtil {
public:
    // C++ string
    static std::string toLower(const std::string& str);
    static std::string toUpper(const std::string& str);
    static std::string removeChars(const std::string& str, const std::string& chars);
    static std::string join(const std::vector<std::string>& strs, const std::string& delimiter);
    static std::string replace(const std::string& str, const std::string& target, const std::string& replacement);
    static std::string trim(const std::string& str);
    static std::string trimLeft(const std::string& str);
    static std::string trimRight(const std::string& str);
    static bool startsWith(const std::string& str, const std::string& prefix);
    static bool endsWith(const std::string& str, const std::string& suffix);
    static bool contains(const std::string& str, const std::string& sub);
    static std::vector<std::string> split(const std::string& str, const std::string& delim);
    static bool match(const std::string& str, const std::regex& pattern);
    static int toInt(const std::string& str);
    static long toLong(const std::string& str);
    static float toFloat(const std::string& str);
    static double toDouble(const std::string& str);
    static size_t countChars(const std::string& str);
    static std::string substring(const std::string& str, size_t start);
    static std::string substring(const std::string& str, size_t start, size_t length);
    static std::string reverse(const std::string& str);
    static std::string padLeft(const std::string& str, size_t totalWidth, char paddingChar);
    static std::string padRight(const std::string& str, size_t totalWidth, char paddingChar);

    // C-style string
    static char* toLower(char* str);
    static char* toUpper(char* str);
    static void freeSplit(char** strs, size_t count);
    static bool match(const char* str, const char* pattern);
    static int compare(const char* str1, const char* str2);
    static int toInt(const char* str);
    static long toLong(const char* str);
    static float toFloat(const char* str);
    static double toDouble(const char* str);
    static bool startsWith(const char* str, const char* prefix);
    static bool endsWith(const char* str, const char* suffix);
    static bool contains(const char* str, const char* sub);
    static size_t countChars(const char* str);
    static size_t byteSize(const char* str);

    // following function needs to free memory by using delete[] 
    static char* removeChars(const char* str, const char* chars);
    static char* join(const char** strs, size_t count, const char* delimiter);
    static char* replace(const char* str, const char* target, const char* replacement);
    static char* trim(const char* str);
    static char* trimLeft(const char* str);
    static char* trimRight(const char* str);
    static char** split(const char* str, const char* delim, size_t* count);
    static char* substring(const char* str, size_t start, size_t length); 
    static char* reverse(const char* str);
    static char* substring(const char* str, size_t start); 
    static char* padLeft(const char* str, size_t totalWidth, char paddingChar);
    static char* padRight(const char* str, size_t totalWidth, char paddingChar); 
    static char* strdup(const char* str);  
private:
    StringUtil() {}
    ~StringUtil() {}
};

#endif // __STRING_UTIL_HEADER__
