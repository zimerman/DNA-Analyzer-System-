#include "FindAll.h"
#include "../Auxiliaryfunctions.h"


bool FindAll::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 3 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#');
}


std::string FindAll::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t idDnaOrginal;
    size_t idDnaSub = 0;
    std::list<size_t> listIndexFind;
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
        listIndexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().findall(containerDna.findInIdMap(idDnaSub)->getDna());
    }
    else
    {
        listIndexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().findall(param.getParam()[2]);
    }

    if(listIndexFind.empty())
    {
        return "this subsequence not in sequence";
    }

    return print(writer, listIndexFind);
}


std::string FindAll::print(Iwriter& writer, std::list<size_t>& listString)
{
    std::string result;

    for (std::list<size_t>::iterator it = listString.begin(); it != listString.end(); it++)
        result += castToString(*it)+" ";
    return result;
}