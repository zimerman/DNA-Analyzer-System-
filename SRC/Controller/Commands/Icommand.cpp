//
// Created by a on 7/5/20.
//

#include <stdexcept>
#include <sstream>
#include "Icommand.h"
#include "../../Model/dataDNA.h"
#include "../Auxiliaryfunctions.h"

std::string Ichange::getName(size_t idDna, const std::string& suffix, dataDNA& containerDna,const std::string& paramater)
{
    std::string NewdnaName;
    if (paramater!="@@")
    {
        NewdnaName = paramater.substr(1);
        if(containerDna.isexistName(NewdnaName))
        {
            return "";
        }
    }
    else
    {
        NewdnaName = containerDna.findInIdMap(idDna)->getName() + suffix +
                     castToString(containerDna.findInIdMap(idDna)->getCountName());
        containerDna.findInIdMap(idDna)->setCountName();
        while(containerDna.isexistName(NewdnaName))
        {
            NewdnaName = containerDna.findInIdMap(idDna)->getName()+suffix+castToString(containerDna.findInIdMap(idDna)->getCountName());
            containerDna.findInIdMap(idDna)->setCountName();
        }
    }
    return NewdnaName;
}
//New::New(const Paramcommand& paramlist)
//{
//    if(!isValid(paramlist))
//        throw std::invalid_argument("command not found");
//
//
//}



