#include "parser_osn.h"
#include <iostream>
#include <QVector>
#include <QStringList>
#include <string.h>
#include <regex>
#include <QDebug>
#include "peremen_pars.h"
#include "function_pars.h"

Parser::Parser(std::string &&str) : _str(str)
{
    findVariables();
    findFunctions();
}

std::vector<peremen> Parser::getVariables()
{
    return _peremen;
}

std::vector<func> Parser::getFunctions()
{
    return _func;
}
std::pair<int, int> Parser::findLogicalErrors()
{
    std::smatch sm;
    std::regex reg1("while\\s*\\((true|false|1|0)\\)\\s*\\{");
    std::string str = _str;
    while (std::regex_search(str, sm, reg1))
    {
        int lineNum = 0;
        int charNum = sm.position() + 1;
        auto lines = QString::fromStdString(_str).split('\n');
        for (const auto& line : lines) {
            lineNum++;
            if (lineNum == 1) {
                if (charNum <= line.length()) {
                    break;
                } else {
                    charNum -= line.length();
                    continue;
                }
            }
            charNum += line.length() + 1;
            if (charNum > sm.position() + 1) {
                break;
            }
        }
        return std::make_pair(lineNum, charNum);
        str = sm.suffix();
    }

    // Если никаких ошибок не найдено, возвращаем (-1, -1)
    return std::make_pair(-1, -1);
}


void Parser::findFunctions()
{

    std::smatch sm, sm2,sm3,sm4;

    std::string str = _str;
    std::regex reg("(int|float|double|short|long\\slong|char|bool|void|string)\\s+(\\w+)\\s*\\((.*)\\)");
    std::regex reg2("(int|float|double|short|long\\slong|char|bool|void|string)\\s+\\w*,?");\

        while(regex_search(str,sm,reg)){
        bool isOverload = false;

        for(size_t i = 0; i < _func.size(); i++){
            if(sm[2].str() == _func[i].getName()){
                isOverload = true;
                break;
            }
        }

        if(isOverload){
            str = sm.suffix();
            continue;
        }

        std::regex reg3( "(int|float|double|short|long\\slong|char|bool|void|string)");
        std::regex reg4( "(int|float|double|short|long\\slong|char|bool|void|string)\\s+"+ sm[2].str() +"\\s*\\((.*)\\)");
        std::vector<pair<int,int>> pos;
        std::vector<std::string> args,overloadArgs;
        std::vector<func> overloadsFunctions;
        std::string tmp =sm[3].str();
        auto strTmp = QString::fromStdString(str).split('\n');
        int overloadsCount = 0 ;

        while(regex_search(tmp,sm2,reg2)){
            args.push_back(sm2[1].str());
            tmp = sm2.suffix();
        }

        for(auto i = 0; i < strTmp.length(); i++){
            auto line = strTmp[i].toStdString();

            while(regex_search(line,sm3,reg4)){
                if(overloadsCount != 0){
                    pos.push_back(make_pair(i+1,sm2.position() + 1));

                    std::string tmp1 = sm3[2].str();
                    overloadArgs.clear();

                    while(regex_search(tmp1,sm4,reg2)){
                        overloadArgs.push_back(sm4[1].str());
                        tmp1 = sm4.suffix();
                    }

                    overloadsFunctions.push_back(func(sm3[1].str(),sm[2].str(),overloadArgs));
                }
                overloadsCount++;
                line = sm3.suffix();
            }
        }
        _func.push_back(func(sm[1].str(), sm[2].str(),overloadsFunctions,args));
        str = sm.suffix();
    }

}

vector<int> Parser::getComplexStructs()
{
    std::smatch classMatch, structMatch,arrayMatch,staticArruy;

    std::regex classReg("(class)\\s+(\\w+)\\s*\\{");
    std::regex structReg("(struct)\\s+(\\w+)\\s*\\{");
    std::regex arrayReg("(\\w+)\\s*[*]\\s*(\\w+)\\s*[=]\\s*(new)\\s*(\\w+)\\s*(\\[)\\s*(\\w+|\\d+)\\s*(\\])"); // \n \\n
    std::regex staticArrayReg("(int|float|double|short|long\\slong|char|bool|void|string)\\s*(\\w+)\\s*(\\[)\\s*(\\d+)\\s*(\\])");

    std::vector<int> counter(4);
    std::string tmp = _str;

    while(regex_search(tmp,classMatch,classReg)){
        tmp = classMatch.suffix();
        counter[0]+=1;
    }

    tmp = _str;

    while(regex_search(tmp,structMatch,structReg)){
        tmp = structMatch.suffix();
        counter[1]+=1;
    }

    tmp = _str;

    while(regex_search(tmp,arrayMatch,arrayReg)){
        tmp = arrayMatch.suffix();
        counter[2]+=1;
    }

    tmp = _str;

    while(regex_search(tmp,staticArruy,staticArrayReg)){
        tmp = staticArruy.suffix();
        counter[3]+=1;
    }

    return counter;
}

vector<pair<int,int>> Parser::getChangePosition()
{
    std::smatch sm;
    std::regex reg("(\\s*(\\S*=\\s*(\\w+))?\\s*;)");
    std::vector<std::pair<int,int>> pos;
    auto strTmp = QString::fromStdString(_str).split('\n');
    int varCount = 0;

    for(auto i = 0; i < strTmp.length(); i++){
        auto line = strTmp[i].toStdString();

        while(regex_search(line,sm,reg)){
            if(varCount != 0){
                pos.push_back(make_pair(i+1,sm.position() + 1));
            }
            varCount++;
            line = sm.suffix();
        }
    }
    return pos;
}

std::vector<std::pair<int,int>> Parser::getBranches()
{

    std::smatch sm;
    std::string inp=_str;
    std::regex reg("(((if|if else)\\s*(\\()(.*)(\\))\\s*)|else)(\\{)");


    std::vector<int> positions;
    int posit=0;

    while(regex_search(inp,sm,reg)){
        positions.push_back(posit+sm.position(0));

        posit += sm.prefix().length() + sm.length();

        inp = sm.suffix();

    }
    int bracketsCounter;
    std::vector<std::pair<int,int>> bracket;

    inp=_str;

    for(size_t i=0; i<positions.size() ;i++){
        int pos=positions[i];
        bracketsCounter=2;
        std::pair<int,int> tmp1(pos,bracketsCounter);
        bracket.push_back(tmp1);

        while(bracketsCounter!=1){

            if(positions[i+1]==pos){

                i++;
                bracketsCounter++;
                std::pair<int,int> tmp(pos,bracketsCounter);
                bracket.push_back(tmp);

            }
            if(inp[pos]=='}'){

                bracketsCounter--;
                std::pair<int,int> tmp(pos,bracketsCounter);
                bracket.push_back(tmp);

            }
            pos++;
        }
    }

    std::vector<std::pair<int,int>> newOne;

    int row=0;
    int column=0;
    int counter=0;


    inp=_str;


    for(int i=0;i<inp.length();i++){

        if(counter < bracket.size() && bracket[counter].first){
            std::pair<int,int> tmp(row,bracket[counter].second);
            newOne.push_back(tmp);
            counter++;
        }
        column++;
        if(inp[i]=='\n'){
            row++;
            column=0;
        }
    }
    return newOne;
}

void Parser::findVariables()
{
    std::regex reg("((int|float|doue|short|long\\slong|char|bool|void|string)\\s(\\w+)\\s*(=\\s*(\\w+))?\\s*;)");
    std::smatch tmp,tmp2;
    std::string str = _str;
    int lineSizeTmp= 0;
    while(regex_search(str,tmp,reg)){
        regex reg2(tmp[3].str() + "(\\s*(\\S*=\\s*(\\w+))?\\s*;)");
        vector<pair<int,int>> pos;
        auto strTmp = QString::fromStdString(str).split('\n');
        int varCount = 0;

        for(auto i = 0; i < strTmp.length(); i++){
            auto line = strTmp[i].toStdString();

            while(regex_search(line,tmp2,reg2)){
                if(varCount != 0){
                    pos.push_back(make_pair(i+1,tmp2.position() + 1));
                }
                varCount++;
                line = tmp2.suffix();
            }
        }

        int bracketsCounter = 0;
        qDebug() << tmp.prefix().length();
        for(auto i = 0; i < tmp.prefix().length() + lineSizeTmp; i++){
            if(_str[i] == '{'){
                bracketsCounter++;
            }
            if(_str[i] == '}'){
                bracketsCounter--;
            }

        }
        lineSizeTmp += tmp.prefix().length();

        _peremen.push_back(peremen(tmp[2].str(),tmp[3].str(), pos, tmp[5].str(),!bracketsCounter));
        str = tmp.suffix();
    }

}
