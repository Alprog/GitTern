
#include <string>

template <typename T>
class DefaultPrettyConverter
{
public:
    static T convert(std::string str)
    {
        throw new std::runtime_error("not implemented");
    }
};

template <>
class DefaultPrettyConverter<std::string>
{
public:
    static std::string convert(std::string str);
};

template <>
class DefaultPrettyConverter<time_t>
{
public:
    static time_t convert(std::string str);
};
