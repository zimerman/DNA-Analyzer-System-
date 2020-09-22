//
// Created by a on 9/16/20.
//

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
        indexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().find(containerDna.findInIdMap(idDnaSub)->getDna(),0);
    }
    else
    {
        indexFind = containerDna.findInIdMap(idDnaOrginal)->getDna().find(param.getParam()[2],0);
    }
    if(indexFind == containerDna.findInIdMap(idDnaOrginal)->getDna().length())
    {
//        print(writer, "this subsequence not in sequence");
//        return;
        return "this subsequence not in sequence";

    }
//    print(writer, castToString(indexFind));
    return castToString(indexFind);

}

//
//void Find::print(const Iwriter& writer, const std::string& string)
//{
//    writer.write(string);
//}
