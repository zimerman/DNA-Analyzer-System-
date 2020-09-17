//
// Created by a on 9/16/20.
//

#include "ReEnum.h"

bool ReEnum::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 1;
}

void ReEnum::run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
}

