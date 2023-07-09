#ifndef FUNC_H
#define FUNC_H
#include <vector>
#include <string>


using namespace std;

class func
{
public:
    func() = default;
    func(string type,string name,vector<func> overloadFuncs,vector<string> funcArgs): _funcName(name),_funcType(type),_overloadFuncs(overloadFuncs),_funcArgs(funcArgs){};
    func(string type,string name,vector<string> funcArgs): _funcName(name),_funcType(type),_funcArgs(funcArgs){};
    string getPrototype();
    string getOverloadsFunc();
    string getName();
    string getType();

private:
    string _funcName;
    string _funcType;
    vector<func> _overloadFuncs;
    vector<string> _funcArgs;
};

#endif // FUNC_H
