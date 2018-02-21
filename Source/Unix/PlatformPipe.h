
#pragma once

#include "Pipe.h"

class UnixPipe : public Pipe
{
public:
    UnixPipe();
    ~UnixPipe();

    virtual std::string readText() override;

private:
    int descriptors[2];
};

using PlatformPipe = UnixPipe;
