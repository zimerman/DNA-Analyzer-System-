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



void Save::run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    std::string fileDnaName;

    std::string string = param.getParam()[1].substr(1);
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
            std::cout<<"name of DNA not found";
            return;
        }
        rawDnaWriter myfile(saveByName(containerDna,param));
        myfile.write(containerDna.findInNameMap(string)->getDna().getAsChar());
    }


    else
    {
        if(!containerDna.isexistId(castToSize(param.getParam()[1].substr(1))))
        {
            std::cout<<"id of DNA not found";
            return;
        }
        rawDnaWriter myfile(saveById(containerDna,param));
        myfile.write(containerDna.findInIdMap(castToSize(string))->getDna().getAsChar());
    }

}
