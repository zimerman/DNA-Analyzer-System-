//
// Created by a on 9/16/20.
//

#include "Len.h"
#include "../Auxiliaryfunctions.h"

bool Len::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 2 &&  param.getParam()[1][0] == '#';
}

void Len::run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    size_t len = containerDna.findInIdMap(castToSize(param.getParam()[1].substr(1)))->getDna().length();
    print(writer, len);
}

void Len::print(const Iwriter& writer, size_t len)
{
    writer.write(castToString(len));
}