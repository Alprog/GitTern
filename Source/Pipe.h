
#pragma once

#include <iostream>
#include <string>

class Pipe
{
public:
    static Pipe* create();

    virtual std::string readText() = 0;

    friend void operator>>(Pipe& pipe, std::string& string);
};
