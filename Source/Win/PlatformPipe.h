
#pragma once

#include "Pipe.h"
#include <windows.h>

class WinPipe : public Pipe
{
public:
    WinPipe();
    ~WinPipe();

    virtual std::string readText() override;

    HANDLE getReadHandle();
    HANDLE getWriteHandle();

private:
    HANDLE readHandle;
    HANDLE writeHandle;
};

using PlatformPipe = WinPipe;
