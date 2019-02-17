
#include <TaskManager.h>

void TaskManager::add(Task* task)
{
    Tasks.push_back(task);
}

void TaskManager::update()
{
    for (auto& task : Tasks)
    {
        task->update();
    }
}
