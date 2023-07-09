#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <QString>
#include <regex>
#include <QVector>
#include <vector>
#include <iomanip>
#include "peremen_pars.h"
#include "function_pars.h"

class Parser
{
public:
    Parser(){};
    Parser(std::string &&str);
    std::pair<int,int>findLogicalErrors();
    std::vector<peremen> getVariables();
    std::vector<func> getFunctions();
    std::vector<int> getComplexStructs();
    std::vector<std::pair<int,int>> getChangePosition();
    std::vector<std::pair<int,int>> getBranches();



private:
    void findVariables();
    void findFunctions();
    std::string _str;

    std::vector<peremen> _peremen;
    std::vector<func> _func;

};

#endif // PARSER_H
