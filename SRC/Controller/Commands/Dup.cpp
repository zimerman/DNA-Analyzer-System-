#include <sstream>
#include "Dup.h"
#include "../Auxiliaryfunctions.h"


bool Dup::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@')))&&(param.getParam()[1][0]=='#'||param.getParam()[1][0]=='@'));
}


Dna* Dup::dup(dataDNA&containerDna, const Paramcommand&param, size_t idDna)
{
    std::string dnaName;

    if(param.getParam().size()<3)
    {
        dnaName = containerDna.findInIdMap(idDna)->getName()+"_"+castToString(containerDna.findInIdMap(idDna)->getCountName());
        containerDna.findInIdMap(idDna)->setCountName();

        while(containerDna.isexistName(dnaName))
        {
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


std::string Dup::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
    {
        throw std::invalid_argument("command not found");

    }
    std::string dnaName;
    size_t idDna;
    idDna = getId(containerDna, param.getParam()[1]);

    if(!idDna)
    {
        return "DNA not found";
    }

    Dna* newDna = dup(containerDna,param, idDna);

    if(!newDna)
    {
        return "This name already Exists";
    }
    containerDna.addDna(newDna);

    return print(writer,containerDna);
}


std::string Dup::print(Iwriter& writer, dataDNA& containerDna)
{
    std::string strId1 = castToString(containerDna.findInIdMap(Dna::getId())->getId());
    return "[" +strId1+ "]"+ containerDna.findInIdMap(Dna::getId())->getName()+":"+containerDna.findInIdMap(Dna::getId())->getDna().getAsChar();
}


