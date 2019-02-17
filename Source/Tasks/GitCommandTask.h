
#pragma once

#include <Task.h>
#include <Process.h>

class GitCommandTask : Task
{
private:
    Process* process;

protected:
    GitCommandTask();
    ~GitCommandTask() override;

    void run(std::string commandLine);

    void onCompleted(std::string text);

public:
    virtual void update() override;
    virtual bool isRunning() override;
    virtual void stop() override;
};
