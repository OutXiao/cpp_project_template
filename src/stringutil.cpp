#include "stringutil.h"

std::string StringUtil::toLower(const std::string &str)
{
    std::string result(str);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
std::string StringUtil::toUpper(const std::string &str)
{
    std::string result(str);
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
std::string StringUtil::removeChars(const std::string &str, const std::string &chars)
{
    std::string result(str);
    for (char c : chars)
    {
        result.erase(std::remove(result.begin(), result.end(), c), result.end());
    }
    return result;
}
std::string StringUtil::join(const std::vector<std::string> &strs, const std::string &delimiter)
{
    std::stringstream ss;
    for (size_t i = 0; i < strs.size(); i++)
    {
        if (i > 0)
        {
            ss << delimiter;
        }
        ss << strs[i];
    }
    return ss.str();
}
std::string StringUtil::replace(const std::string &str, const std::string &target, const std::string &replacement)
{
    std::string result(str);
    size_t pos = 0;
    while ((pos = result.find(target, pos)) != std::string::npos)
    {
        result.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
    return result;
}
std::string StringUtil::trim(const std::string &str)
{
    std::string result(str);
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int ch)
                                              { return !std::isspace(ch); }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](int ch)
                              { return !std::isspace(ch); })
                     .base(),
                 result.end());
    return result;
}
std::string StringUtil::trimLeft(const std::string &str)
{
    std::string result(str);
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int ch)
                                              { return !std::isspace(ch); }));
    return result;
}
std::string StringUtil::trimRight(const std::string &str)
{
    std::string result(str);
    result.erase(std::find_if(result.rbegin(), result.rend(), [](int ch)
                              { return !std::isspace(ch); })
                     .base(),
                 result.end());
    return result;
}
bool StringUtil::startsWith(const std::string &str, const std::string &prefix)
{
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}
bool StringUtil::endsWith(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}
bool StringUtil::contains(const std::string &str, const std::string &sub)
{
    return str.find(sub) != std::string::npos;
}
std::vector<std::string> StringUtil::split(const std::string &s, const std::string &delim)
{
    std::string str(s);
    std::vector<std::string> result;
    size_t pos = 0;
    while ((pos = str.find(delim)) != std::string::npos)
    {
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + delim.length());
    }
    result.push_back(str);
    return result;
}
bool StringUtil::match(const std::string &str, const std::regex &pattern)
{
    return std::regex_match(str, pattern);
}
int StringUtil::toInt(const std::string &str)
{
    return std::stoi(str);
}
long StringUtil::toLong(const std::string &str)
{
    return std::stol(str);
}
float StringUtil::toFloat(const std::string &str)
{
    return std::stof(str);
}
double StringUtil::toDouble(const std::string &str)
{
    return std::stod(str);
}
size_t StringUtil::countChars(const std::string &str)
{
    return std::count_if(str.begin(), str.end(), [](unsigned char c)
                         { return std::isalpha(c); });
}
std::string StringUtil::substring(const std::string &str, size_t start)
{
    return str.substr(start);
}
std::string StringUtil::substring(const std::string &str, size_t start, size_t length)
{
    return str.substr(start, length);
}
std::string StringUtil::reverse(const std::string &str)
{
    std::string result(str);
    std::reverse(result.begin(), result.end());
    return result;
}
std::string StringUtil::padLeft(const std::string &str, size_t totalWidth, char paddingChar)
{
    if (str.length() >= totalWidth)
    {
        return str;
    }
    std::string result(totalWidth - str.length(), paddingChar);
    result.append(str);
    return result;
}
std::string StringUtil::padRight(const std::string &str, size_t totalWidth, char paddingChar)
{
    if (str.length() >= totalWidth)
    {
        return str;
    }
    std::string result(totalWidth - str.length(), paddingChar);
    result.insert(result.begin(), str.begin(), str.end());
    return result;
}
// C-style string
char *StringUtil::toLower(char *str)
{
    char *p = str;
    while (*p)
    {
        *p = std::tolower(*p);
        p++;
    }
    return str;
}
char *StringUtil::toUpper(char *str)
{
    char *p = str;
    while (*p)
    {
        *p = std::toupper(*p);
        p++;
    }
    return str;
}
char *StringUtil::removeChars(const char *str, const char *chars)
{
    size_t len = std::strlen(str);
    char *result = new char[len + 1];
    std::memset(result, 0, len + 1);
    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (std::strchr(chars, str[i]) == nullptr)
        {
            result[j++] = str[i];
        }
    }
    return result;
}
char *StringUtil::join(const char **strs, size_t count, const char *delimiter)
{
    std::stringstream ss;
    for (size_t i = 0; i < count; i++)
    {
        if (i > 0)
        {
            ss << delimiter;
        }
        ss << strs[i];
    }
    std::string result = ss.str();
    char *cstr = new char[result.length() + 1];
    std::strcpy(cstr, result.c_str());
    return cstr;
}
char *StringUtil::replace(const char *str, const char *target, const char *replacement)
{
    std::string result(str);
    size_t pos = 0;
    while ((pos = result.find(target, pos)) != std::string::npos)
    {
        result.replace(pos, std::strlen(target), replacement);
        pos += std::strlen(replacement);
    }
    char *cstr = new char[result.length() + 1];
    std::strcpy(cstr, result.c_str());
    return cstr;
}
char *StringUtil::trim(const char *str)
{
    std::string result(str);
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int ch)
                                              { return !std::isspace(ch); }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](int ch)
                              { return !std::isspace(ch); })
                     .base(),
                 result.end());
    char *cstr = new char[result.length() + 1];
    std::strcpy(cstr, result.c_str());
    return cstr;
}
char *StringUtil::trimLeft(const char *str)
{
    std::string result(str);
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int ch)
                                              { return !std::isspace(ch); }));
    char *cstr = new char[result.length() + 1];
    std::strcpy(cstr, result.c_str());
    return cstr;
}
char *StringUtil::trimRight(const char *str)
{
    std::string result(str);
    result.erase(std::find_if(result.rbegin(), result.rend(), [](int ch)
                              { return !std::isspace(ch); })
                     .base(),
                 result.end());
    char *cstr = new char[result.length() + 1];
    std::strcpy(cstr, result.c_str());
    return cstr;
}
bool StringUtil::startsWith(const char *str, const char *prefix)
{
    return std::strncmp(str, prefix, std::strlen(prefix)) == 0;
}
bool StringUtil::endsWith(const char *str, const char *suffix)
{
    size_t len1 = std::strlen(str);
    size_t len2 = std::strlen(suffix);
    return len1 >= len2 && std::strncmp(str + len1 - len2, suffix, len2) == 0;
}
bool StringUtil::contains(const char *str, const char *sub)
{
    return std::strstr(str, sub) != nullptr;
}
char **StringUtil::split(const char *str, const char *delim, size_t *count)
{
    std::vector<std::string> result = split(std::string(str), std::string(delim));
    *count = result.size();
    char **strs = new char *[*count];
    for (size_t i = 0; i < *count; i++)
    {
        strs[i] = new char[result[i].length() + 1];
        std::strcpy(strs[i], result[i].c_str());
    }
    return strs;
}
void StringUtil::freeSplit(char **strs, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        delete[] strs[i];
    }
    delete[] strs;
}
bool StringUtil::match(const char *str, const char *pattern)
{
    std::regex re(pattern);
    return std::regex_match(str, re);
}
int StringUtil::toInt(const char *str)
{
    return std::atoi(str);
}
long StringUtil::toLong(const char *str)
{
    return std::atol(str);
}
float StringUtil::toFloat(const char *str)
{
    return std::atof(str);
}
double StringUtil::toDouble(const char *str)
{
    return std::strtod(str, nullptr);
}
size_t StringUtil::countChars(const char *str)
{
    size_t count = 0;
    while (*str)
    {
        if (std::isalpha(*str))
        {
            count++;
        }
        str++;
    }
    return count;
}
size_t StringUtil::byteSize(const char *str)
{
    return std::strlen(str) * sizeof(char);
}
char *StringUtil::substring(const char *str, size_t start)
{
    return strdup(str + start);
}
char *StringUtil::substring(const char *str, size_t start, size_t length)
{
    char *result = new char[length + 1];
    std::strncpy(result, str + start, length);
    result[length] = '\0';
    return result;
}
char *StringUtil::reverse(const char *str)
{
    size_t len = std::strlen(str);
    char *result = new char[len + 1];
    std::strcpy(result, str);
    std::reverse(result, result + len);
    return result;
}
char *StringUtil::padLeft(const char *str, size_t totalWidth, char paddingChar)
{
    size_t len = std::strlen(str);
    if (len >= totalWidth)
    {
        return strdup(str);
    }
    char *result = new char[totalWidth + 1];
    std::memset(result, paddingChar, totalWidth - len);
    std::strcpy(result + totalWidth - len, str);
    return result;
}
char *StringUtil::padRight(const char *str, size_t totalWidth, char paddingChar)
{
    size_t len = std::strlen(str);
    if (len >= totalWidth)
    {
        return strdup(str);
    }
    char *result = new char[totalWidth + 1];
    std::strcpy(result, str);
    std::memset(result + len, paddingChar, totalWidth - len);
    result[totalWidth] = '\0';
    return result;
}
int StringUtil::compare(const char *str1, const char *str2)
{
    return std::strcmp(str1, str2);
}

char *StringUtil::strdup(const char *str)
{
    std::string s(str);
    char *result = new char[s.length() + 1];
    std::strcpy(result, s.c_str());
    return result;
}