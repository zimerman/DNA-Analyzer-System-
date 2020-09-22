//
// Created by a on 7/6/20.
//

#include <sstream>
#include "Save.h"
#include "../Auxiliaryfunctions.h"
//Save::Save(const Paramcommand& obj)
//{
//
//        if(!isValid(obj))
//            throw std::invalid_argument("command not found");
//
//}

bool Save::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@')))&&(param.getParam()[1][0]=='#'||param.getParam()[1][0]=='@'));
}

std::string Save::saveById(dataDNA& containerDna, const Paramcommand&param)
{
    std::string fileDnaName;
    std::string string = param.getParam()[1].substr(1);
    size_t idDna = castToSize(string);
    if(param.getParam().size()<3)
    {
        fileDnaName = containerDna.findInIdMap(idDna)->getName()+".rawdna";
    }
    else
    {
        fileDnaName = param.getParam()[2].substr(1)+".rawdna";
    }
    containerDna.findInIdMap(idDna)->getStatus().setStatus("up to date", idDna);
    return fileDnaName;

}


std::string Save::saveByName(dataDNA& containerDna, const Paramcommand&param)
{
    std::string fileDnaName;
    std::string name = param.getParam()[1].substr(1);
    if(param.getParam().size()<3)
    {
        fileDnaName = containerDna.findInNameMap(name)->getName()+".rawdna";
    }
    else
    {
        fileDnaName = param.getParam()[2].substr(1)+".rawdna";
    }
    containerDna.findInNameMap(name)->getStatus().setStatus("up to date", containerDna.findIdByName(name));
    return fileDnaName;
}



std::string Save::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    std::string fileDnaName;

    std::string string = param.getParam()[1].substr(1);
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
//            writer.write("name of DNA not found");
//            return;
            return "name of DNA not found";
        }
        rawDnaWriter myfile(saveByName(containerDna,param));
        myfile.write(containerDna.findInNameMap(string)->getDna().getAsChar());
    }


    else
    {
        if(!containerDna.isexistId(castToSize(param.getParam()[1].substr(1))))
        {
//            writer.write("id of DNA not found");
//            return;
            return "id of DNA not found";
        }
        rawDnaWriter myfile(saveById(containerDna,param));
        myfile.write(containerDna.findInIdMap(castToSize(string))->getDna().getAsChar());
    }
    return "";
}
