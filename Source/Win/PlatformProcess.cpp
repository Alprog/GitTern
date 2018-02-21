
#include <PlatformProcess.h>
#include <PlatformPipe.h>

#include <locale>
#include <codecvt>
#include <io.h>

WinProcess::WinProcess()
    : handle{0}
{
}

WinProcess::~WinProcess()
{
    stop();
}

void WinProcess::run(std::string path, std::string commandLine, std::string directory)
{
    stop();

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    auto wpath = converter.from_bytes(path.c_str());
    auto wcommandLine = converter.from_bytes(commandLine.c_str());
    auto wdirectory = converter.from_bytes(directory.c_str());


    pipe = Pipe::create();

    STARTUPINFO startupinfo;
    ZeroMemory(&startupinfo, sizeof(startupinfo));
    startupinfo.cb = sizeof(STARTUPINFO);
    //startupinfo.hStdInput = g_hChildStd_IN_Rd;
    startupinfo.hStdOutput = static_cast<PlatformPipe*>(pipe)->getWriteHandle();
    startupinfo.hStdError = static_cast<PlatformPipe*>(pipe)->getWriteHandle();
    startupinfo.dwFlags |= STARTF_USESTDHANDLES;

    PROCESS_INFORMATION processInfo;
    ZeroMemory(&(processInfo), sizeof(processInfo));

    auto result = CreateProcess(wpath.c_str(), &wcommandLine[0], 0, 0, TRUE, CREATE_NO_WINDOW, 0, wdirectory.c_str(), &startupinfo, &processInfo);
    if (result != 0)
    {
        handle = processInfo.hProcess;
    }
}

void WinProcess::stop()
{
    if (isRunning())
    {
        TerminateProcess(handle, 1);
    }
    handle = 0;
}

bool WinProcess::isRunning()
{
    if (handle != 0)
    {
        DWORD exitCode;
        GetExitCodeProcess(handle, &exitCode);
        if (exitCode == STILL_ACTIVE)
        {
            return true;
        }
        else
        {
            handle = 0;
        }
    }
    return false;
}

void WinProcess::writeInput(std::string inputString)
{

}

std::string WinProcess::readOutput()
{
    return pipe->readText();
}
