#include "function_pars.h"

string func::getName()
{
    return _funcName;
}

string func::getType()
{
    return _funcType;
}

string func::getPrototype()
{
    string args = "";
    for(auto i : _funcArgs){
        args += i + ", ";
    }

    return _funcType + " " + _funcName + " (" + args + ");";
}

string func::getOverloadsFunc()
{
    string str;
    for(size_t i = 0; i < _overloadFuncs.size(); i++){
        str += " " + _overloadFuncs[i].getPrototype() + "\n";
    }
    return str;
}
