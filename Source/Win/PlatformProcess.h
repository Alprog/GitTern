
#pragma once

#include "Process.h"
#include <windows.h>
#include "Pipe.h"

class WinProcess : public Process
{
public:
    WinProcess();
    ~WinProcess() override;

    virtual void run(std::string path, std::string commandLine, std::string workingDirectory) override;
    virtual void stop() override;
    virtual bool isRunning() override;
    virtual void writeInput(std::string inputString) override;
    virtual std::string readOutput() override;

    Pipe* pipe;

    HANDLE handle;
};

using PlatformProcess = WinProcess;
