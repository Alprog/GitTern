
#pragma once

#include <GitCommandTask.h>

class GetLogTask : public GitCommandTask
{
public:
    GetLogTask(int count);
};
