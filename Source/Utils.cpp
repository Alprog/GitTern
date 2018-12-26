
#include "Utils.h"
#include <algorithm>
#include <sstream>

std::vector<std::string> split(std::string string, std::string separator)
{
    std::vector<std::string> result;

    auto separatorSize = separator.size();
    auto pattern = separator.c_str();

    auto size = string.size();
    std::string::size_type index = 0;
    while (index < size)
    {
        auto lastIndex = string.find(pattern, index);
        if (lastIndex == std::string::npos)
        {
            lastIndex = size;
        }

        auto subStr = string.substr(index, lastIndex - index);
        result.push_back(subStr);
        index = lastIndex + separatorSize;
    }

    return result;
}

std::string join(std::vector<std::string> vector, std::string separator)
{
    std::stringstream stream;

    auto size = vector.size();
    if (size > 0)
    {
        stream << vector[0];
        for (size_t i = 1; i < size; i++)
        {
            stream << separator << vector[i];
        }
    }

    return stream.str();
}

void replace(std::string& string, std::string oldValue, std::string newValue)
{
    while (true)
    {
        auto index = string.find(oldValue.c_str());
        if (index == std::string::npos)
        {
            break;
        }
        string.replace(index, oldValue.size(), newValue);
    }
}

bool startsWith(const std::string& string, const std::string& pattern)
{
    return string.substr(0, pattern.size()) == pattern;
}

bool endsWith(const std::string& string, const std::string& pattern)
{
    auto stringSize = string.size();
    auto patternSize = string.size();
    if (stringSize >= patternSize)
    {
        return string.substr(stringSize - patternSize, patternSize) == pattern;
    }
    return false;
}
