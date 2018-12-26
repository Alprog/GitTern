
#pragma once
#include <string>

struct Commit
{
    std::string guid;
    std::string author;
    time_t timestamp;
    std::string title;
};
