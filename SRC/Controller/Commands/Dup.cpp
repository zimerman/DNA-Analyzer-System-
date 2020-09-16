//
// Created by a on 7/7/20.
//

#include <sstream>
#include "Dup.h"
#include "../Auxiliaryfunctions.h"
//Dup::Dup(const Paramcommand& obj)
//{
//    if(!isValid(obj))
//    {
//        throw std::invalid_argument("command not found");
//
//    }
//
//}

bool Dup::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@')))&&(param.getParam()[1][0]=='#'||param.getParam()[1][0]=='@'));
}



Dna* Dup::dupByName(dataDNA&containerDna, const Paramcommand&param) {
    std::string string = param.getParam()[1].substr(1);
    std::string dnaName;
    if (param.getParam().size() < 3) {

        dnaName = containerDna.findInNameMap(string)->getName() + "_" +
                  castToString(containerDna.findInNameMap(string)->getCountName());
        containerDna.findInNameMap(string)->setCountName();
        while (containerDna.isexistName(dnaName)) {
            dnaName = containerDna.findInNameMap(string)->getName() + "_" +
                      castToString(containerDna.findInNameMap(string)->getCountName());
            containerDna.findInNameMap(string)->setCountName();
        }

    } else {
        dnaName = param.getParam()[2].substr(1);
        if(containerDna.isexistName(dnaName))
        {
            return NULL;

        }
    }
    Dna *newdna = new Dna(dnaName, "new", containerDna.findInNameMap(string)->getDna());
    return newdna;
}
Dna* Dup::dupById(dataDNA&containerDna, const Paramcommand&param)
{
    size_t idDna = castToSize(param.getParam()[1].substr(1));
    std::string dnaName;
    if(param.getParam().size()<3)
    {
        dnaName = containerDna.findInIdMap(idDna)->getName()+"_"+castToString(containerDna.findInIdMap(idDna)->getCountName());
        containerDna.findInIdMap(idDna)->setCountName();
        while(containerDna.isexistName(dnaName))
        {
            std::cout<<"dup!!!!1";
            dnaName = containerDna.findInIdMap(idDna)->getName()+"_"+castToString(containerDna.findInIdMap(idDna)->getCountName());
            containerDna.findInIdMap(idDna)->setCountName();
        }

    }
    else
    {
        dnaName = param.getParam()[2].substr(1);
        if(containerDna.isexistName(dnaName))
        {
            return NULL;

        }
    }
    Dna* newdna = new Dna(dnaName, "new",containerDna.findInIdMap(idDna)->getDna());
    return newdna;
}

void Dup::run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
    {
        throw std::invalid_argument("command not found");

    }
    std::string dnaName;
    std::string string = param.getParam()[1].substr(1);
    size_t idDna = castToSize(string);

    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(string))
        {
            std::cout<<"name of DNA not found";
            return;
        }
        Dna* newDna = dupByName(containerDna,param);
        if(!newDna)
        {
            writer.write("This name already Exists");
            return;
        }
        containerDna.addDna(newDna);

    }
    else
    {

        if(!containerDna.isexistId(idDna))
        {
            std::cout<<"id of DNA not found";
            return;
        }
        Dna* newDna = dupById(containerDna,param);
        if(!newDna)
        {
            writer.write("This name already Exists");
            return;
        }
        containerDna.addDna(newDna);
    }

    print(writer,containerDna);

}

void Dup::print(const Iwriter& writer, dataDNA& containerDna)
{

    std::string strId1 = castToString(containerDna.findInIdMap(Dna::getId())->getId());
    writer.write("[" +strId1+ "]"+ containerDna.findInIdMap(Dna::getId())->getName()+":"+containerDna.findInIdMap(Dna::getId())->getDna().getAsChar());

}
