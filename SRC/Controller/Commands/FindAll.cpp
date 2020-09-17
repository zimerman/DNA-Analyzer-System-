//
// Created by a on 9/16/20.
//

#include "FindAll.h"
#include "../Auxiliaryfunctions.h"

bool FindAll::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 3 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#');
}


void FindAll::run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    size_t idDnaOrginal;
    size_t idDnaSub = 0;
    std::list<size_t> listIndexFind;
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
            writer.write("name of DNA not found");
            return;
        }
        idDnaOrginal = containerDna.findIdByName(param.getParam()[1].substr(1));
    }

    else
    {
        idDnaOrginal = castToSize(param.getParam()[1].substr(1));
        if(!containerDna.isexistId(idDnaOrginal))
        {
            writer.write("id of DNA not found");
            return;
        }
    }
    if(param.getParam()[2][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[2].substr(1)))
        {
            writer.write("name of DNA not found");
            return;
        }
        idDnaSub = containerDna.findIdByName(param.getParam()[2].substr(1));
    }

    else if(param.getParam()[2][0]=='#')
    {
        idDnaSub = castToSize(param.getParam()[2].substr(1));
        if(!containerDna.isexistId(idDnaSub))
        {
            writer.write("id of DNA not found");
            return;
        }
    }
    if(idDnaSub)
    {
        listIndexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().findall(containerDna.findInIdMap(idDnaSub)->getDna());
    }
    else
    {
        listIndexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().findall(param.getParam()[2]);
    }

    if(*(listIndexFind.begin()) == containerDna.findInIdMap(idDnaOrginal)->getDna().length())
    {
        writer.write("this subsequence not in sequence");
        return;
    }
    print(writer, listIndexFind);
}


void FindAll::print(const Iwriter& writer, std::list<size_t>& listString)
{
    for (std::list<size_t>::iterator it = listString.begin(); it != listString.end(); it++)
        writer.write(castToString(*it));
}