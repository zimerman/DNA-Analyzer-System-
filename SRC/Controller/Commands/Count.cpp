//
// Created by a on 9/16/20.
//

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
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
//            writer.write("name of DNA not found");
//            return;
            return "name of DNA not found";
        }
        idDnaOrginal = containerDna.findIdByName(param.getParam()[1].substr(1));
    }

    else
    {
        idDnaOrginal = castToSize(param.getParam()[1].substr(1));
        if(!containerDna.isexistId(idDnaOrginal))
        {
//            writer.write("id of DNA not found");
//            return;
              return "id of DNA not found";
        }
    }
    if(param.getParam()[2][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[2].substr(1)))
        {
//            writer.write("name of DNA not found");
//            return;
            return "name of DNA not found";
        }
        idDnaSub = containerDna.findIdByName(param.getParam()[2].substr(1));
    }

    else if(param.getParam()[2][0]=='#')
    {
        idDnaSub = castToSize(param.getParam()[2].substr(1));
        if(!containerDna.isexistId(idDnaSub))
        {
//            writer.write("id of DNA not found");
//            return;
            return "id of DNA not found";
        }
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
//    print(writer, castToString(NumIndexFind));
}

//void Count::print(const Iwriter& writer, const std::string& string)
//{
//    writer.write(string);
//}