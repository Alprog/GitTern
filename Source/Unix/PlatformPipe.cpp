
#include "PlatformPipe.h"

#include <unistd.h>
#include <fcntl.h>
#include "iostream"
#include "stdio.h"

enum Pipes
{
    READ, WRITE
};

UnixPipe::UnixPipe()
{
    pipe(descriptors);
    /*if (file != nullptr)
    {
        dup2(descriptors[WRITE], fileno(file));
    }*/

    // make none-blocking
    auto flags = fcntl(descriptors[READ], F_GETFL);
    fcntl(descriptors[READ], F_SETFL, flags | O_NONBLOCK);
}

UnixPipe::~UnixPipe()
{
    close(descriptors[READ]);
    close(descriptors[WRITE]);
}

std::string UnixPipe::readText()
{
    const int MAX = 1024;
    std::string result;
    char buffer[MAX + 1];
    int f = descriptors[READ];

    int count = 0;
    do
    {
        count = read(f, buffer, MAX);
        if (count > 0)
        {
            buffer[count] = 0;
            result += buffer;
        }
    }
    while (count == MAX);
    return result;
}
