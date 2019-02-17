
#include <GitCommandTask.h>
#include <Process.h>

GitCommandTask::GitCommandTask()
{
}

GitCommandTask::~GitCommandTask()
{
    stop();
}

void GitCommandTask::run(std::string commandLine)
{
    auto path = "C:/Program Files/Git/cmd/git.exe";
    auto directory = "C:/GitTern";

    process->run(path, "git " + commandLine, directory);
}

void GitCommandTask::onCompleted(std::string text)
{

}

void GitCommandTask::update()
{

}

bool GitCommandTask::isRunning()
{
    return process != nullptr && process->isRunning();
}

void GitCommandTask::stop()
{
    if (process)
    {
        process->stop();
        process = nullptr;
    }
}
