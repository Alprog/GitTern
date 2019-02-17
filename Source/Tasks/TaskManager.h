
#pragma once

#include <Task.h>
#include <vector>

class TaskManager
{
private:
    std::vector<Task*> Tasks;

public:
    void add(Task* task);

    void update();
};
