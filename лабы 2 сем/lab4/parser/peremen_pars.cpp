#include "peremen_pars.h"

string peremen::getType()
{
    return _type;
}

string peremen::getPositions()
{
    string tmp;
    for(size_t i = 0; i < _changingPos.size();i++){
        stringstream ss,ss2;
        ss << _changingPos[i].first;
        ss2 << _changingPos[i].second;

        tmp += ss.str() + " " + ss2.str() + "\n";
    }
    return tmp;
}

string peremen::getName()
{
    return _name;
}

string peremen::getDefaulValue()
{
    if(_defaultValue == "")
        return "-";
    return _defaultValue;
}

string peremen::getVisibilityArea()
{
    if(_isGlobal)
        return "(global)";
    return "(local)";
}
