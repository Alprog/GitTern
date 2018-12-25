
#pragma once

#include <vector>
#include "PrettyRecord.h"

template <class T>
class PrettyFormatter
{
private:
    std::vector<PrettyRecord> records;

public:
    std::vector<T> parse(std::string text);
};
