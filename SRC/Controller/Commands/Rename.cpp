//
// Created by a on 9/16/20.
//

#include "Rename.h"
#include "../Auxiliaryfunctions.h"

bool Rename::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 3 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#') && param.getParam()[2][0] == '@';
}

std::string Rename::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    size_t idDna;
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
//            writer.write("name of DNA not found");
//            return;
            return "name of DNA not found";
        }
        idDna = containerDna.findIdByName(param.getParam()[1].substr(1));
    }

    else
    {
        idDna = castToSize(param.getParam()[1].substr(1));
        if(!containerDna.isexistId(idDna))
        {
//            writer.write("id of DNA not found");
//            return;
            return "id of DNA not found";
        }
    }
//    std::cout<<containerDna.findInIdMap(idDna)->getName();
//    std::cout<<param.getParam()[2].substr(1)<<"\n";
    containerDna.setName(idDna, param.getParam()[2].substr(1));
    return "";
}

