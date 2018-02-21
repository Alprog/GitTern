
#include <Pipe.h>
#include <PlatformPipe.h>

Pipe* Pipe::create()
{
    return new PlatformPipe();
}

void operator>>(Pipe& pipe, std::string& string)
{
    string += pipe.readText();
}
