//
// Created by a on 9/14/20.
//

#include "New.h"
#include "../Auxiliaryfunctions.h"

bool New::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@'))));

}


void New::run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param)
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
        writer.write("This name already Exists");
        return;
    }

    Dna* newdna = new Dna(dnaName, "new",param.getParam()[1]);
    containerDna.addDna(newdna);
    print(writer,containerDna);

}
void New::print(const Iwriter& writer, dataDNA& containerDna)
{

    std::string strId =castToString(containerDna.findInIdMap(Dna::getId())->getId());
    writer.write("[" +strId+ "]"+ containerDna.findInIdMap(Dna::getId())->getName()+":"+containerDna.findInIdMap(Dna::getId())->getDna().getAsChar());

}
