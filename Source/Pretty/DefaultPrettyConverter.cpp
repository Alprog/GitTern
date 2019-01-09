
#include <DefaultPrettyConverter.h>

std::string DefaultPrettyConverter<std::string>::convert(std::string str)
{
    return str;
}

time_t DefaultPrettyConverter<time_t>::convert(std::string str)
{
    return 0;
}
