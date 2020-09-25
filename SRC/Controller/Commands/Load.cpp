#include <stdexcept>
#include "Load.h"
#include "../../View/rawDnaReader.h"
#include "../Auxiliaryfunctions.h"


bool Load::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@'))));
}


std::string Load::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    rawDnaReader myfile(param.getParam()[1]);
    myfile.read();
    std::string filename=param.getParam()[1];
    std::string dnaName;
    std::string string = param.getParam()[1].substr(0, param.getParam()[1].find(".rawdna"));

    if(param.getParam().size()<3)
    {

        dnaName = param.getParam()[1].substr(0, param.getParam()[1].find(".rawdna"));

        while(containerDna.isexistName(dnaName))
        {
            dnaName = string+"_"+castToString(containerDna.findInNameMap(string)->getCountName());
            containerDna.findInNameMap(string)->setCountName();
        }
    }

    else
    {
        dnaName = param.getParam()[2].substr(1);

    }

    if(containerDna.isexistName(dnaName))
    {
        return "This name already Exists";
    }

    Dna* newdna = new Dna(dnaName.substr(0, dnaName.find(".rawdna")),"up to date",myfile);
    containerDna.addDna(newdna);

    return print(writer,containerDna);
}


std::string Load::print(Iwriter &writer, dataDNA& containerDna)const
{

    std::string strId =castToString(containerDna.findInIdMap(Dna::getId())->getId());

    if(containerDna.findInIdMap(Dna::getId())->getDna().length()<40)
    {
        return "[" + strId + "]" + containerDna.findInIdMap(Dna::getId())->getName() + ":" +
                            containerDna.findInIdMap(Dna::getId())->getDna().getAsChar();
    }
    else
    {
        std::string lastDnasequence= (containerDna.findInIdMap(Dna::getId())->getDna()).getAsChar()+containerDna.findInIdMap(Dna::getId())->getDna().length()-3;
        std::string firstDnasequence(containerDna.findInIdMap(Dna::getId())->getDna().getAsChar());
        firstDnasequence = firstDnasequence.substr(0,32);

        return "[" + strId + "]" + containerDna.findInIdMap(Dna::getId())->getName() + ":" + firstDnasequence+"..."+lastDnasequence;
    }
}


