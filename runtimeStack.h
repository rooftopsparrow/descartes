
#ifndef RUNTIMESTACK_h
#define RUNTIMESTACK_h

#include <map>

using namespace std;

class RuntimeStack
{

    public:
        map<string, double> symbolTable;
        RuntimeStack() {};

};

#endif