
#include "PlatformPipe.h"

#include <algorithm>


WinPipe::WinPipe()
{
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;
    if (!CreatePipe(&readHandle, &writeHandle, &saAttr, NULL))
        throw new std::exception("can't create pipe");
}

WinPipe::~WinPipe()
{
    CloseHandle(readHandle);
    CloseHandle(writeHandle);
}

std::string WinPipe::readText()
{
    const DWORD MAX_SIZE = 1024;

    std::string result;
    while (true)
    {
        DWORD availableCount;
        if (!PeekNamedPipe(readHandle, nullptr, 0, nullptr, &availableCount, nullptr))
            throw new std::exception("can't peek pipe");

        if (availableCount == 0)
            break;

        char buffer[MAX_SIZE + 1];
        auto readCount = availableCount > MAX_SIZE ? MAX_SIZE : availableCount;
        if (!ReadFile(readHandle, buffer, readCount, NULL, NULL))
            throw new std::exception("can't read pipe");
        buffer[readCount] = 0;

        result += buffer;
        if (readCount == availableCount)
            break;
    }

    return result;
}

HANDLE WinPipe::getReadHandle()
{
    return readHandle;
}

HANDLE WinPipe::getWriteHandle()
{
    return writeHandle;
}
