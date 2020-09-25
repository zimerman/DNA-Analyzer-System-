#include "Find.h"
#include "../Auxiliaryfunctions.h"


bool Find::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 3 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#');
}


std::string Find::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t idDnaOrginal;
    size_t idDnaSub = 0;
    size_t indexFind;
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
        indexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().find(containerDna.findInIdMap(idDnaSub)->getDna(),0);
    }
    else
    {
        indexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().find(param.getParam()[2],0);
    }

    if(indexFind == containerDna.findInIdMap(idDnaOrginal)->getDna().length())
    {
        return "this subsequence not in sequence";
    }

    return castToString(indexFind);
}

