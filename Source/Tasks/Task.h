
#pragma once

class Task
{
public:
    Task();
    virtual ~Task();

    virtual void update() = 0;
    virtual bool isRunning() = 0;
    virtual void stop() = 0;
};
