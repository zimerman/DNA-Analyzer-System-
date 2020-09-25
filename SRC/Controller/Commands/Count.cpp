#include "Count.h"
#include "../Auxiliaryfunctions.h"

bool Count::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 3 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#');
}


std::string Count::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t idDnaOrginal;
    size_t idDnaSub = 0;
    size_t NumIndexFind;
    idDnaOrginal = getId(containerDna, param.getParam()[1]);

    if(!idDnaOrginal)
    {
        return "DNA not found";
    }
    idDnaSub = getId(containerDna, param.getParam()[2]);

    if(!idDnaSub && (param.getParam()[2][0] == '#' || param.getParam()[2][0] == '@'))
    {
        return "DNA not found";
    }

    if(idDnaSub)
    {
        NumIndexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().count(containerDna.findInIdMap(idDnaSub)->getDna());
    }
    else
    {
        NumIndexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().count(param.getParam()[2]);
    }

    return castToString(NumIndexFind);
}

