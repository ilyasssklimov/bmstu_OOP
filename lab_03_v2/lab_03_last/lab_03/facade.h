#ifndef FACADE_H
#define FACADE_H

#include "commands.h"


using namespace std;


class Facade
{
public:
    void execute_command(shared_ptr<base_command> command);
};

#endif // FACADE_H
