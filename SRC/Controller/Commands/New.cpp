#include "New.h"
#include "../Auxiliaryfunctions.h"


bool New::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@'))));
}


std::string New::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    static size_t countId=0;
    std::string dnaName;

    if(param.getParam().size()<3)
    {
        dnaName = "seq"+castToString(++countId);
        while(containerDna.isexistName(dnaName))
        {
            dnaName = "seq"+castToString(++countId);
        }
    }
    else
    {
        dnaName = param.getParam()[2].substr(1);;
    }

    if(containerDna.isexistName(dnaName))
    {
        return "This name already Exists";
    }

    Dna* newdna = new Dna(dnaName, "new",param.getParam()[1]);
    containerDna.addDna(newdna);
    return print(writer,containerDna);
}


std::string New::print(Iwriter& writer, dataDNA& containerDna)
{
    std::string strId =castToString(containerDna.findInIdMap(Dna::getId())->getId());

    return "[" +strId+ "]"+ containerDna.findInIdMap(Dna::getId())->getName()+":"+containerDna.findInIdMap(Dna::getId())->getDna().getAsChar();
}
