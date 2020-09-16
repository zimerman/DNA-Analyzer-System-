//
// Created by a on 7/6/20.
//

#include <stdexcept>
#include <sstream>
#include "Load.h"
#include "../../View/rawDnaReader.h"
#include "../Auxiliaryfunctions.h"
bool Load::isValid(const Paramcommand& param)
{
    std::cout<<"dh";
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@'))));
}

//Load::Load(const Paramcommand& param)
//{
//    if(!isValid(param))
//        throw std::invalid_argument("command not found");
//
//}


void Load::run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& param)
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

//        dnaName = param.getParam()[1];
        dnaName = param.getParam()[1].substr(0, param.getParam()[1].find(".rawdna"));
//       if(containerDna.isexistName(dnaName))
//       {
//           dnaName=param.getParam()[1]+"_"+castToString(containerDna.findInNameMap(dnaName)->getCountName());
//
//       }
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
        writer.write("This name already Exists");
        return;

    }
    Dna* newdna = new Dna(dnaName.substr(0, dnaName.find(".rawdna")),"new",myfile);
    containerDna.addDna(newdna);
    print(writer,containerDna);

}


void Load::print(const Iwriter& writer, dataDNA& containerDna)const
{

    std::string strId =castToString(containerDna.findInIdMap(Dna::getId())->getId());



    if(containerDna.findInIdMap(Dna::getId())->getDna().length()<40)
    {
        writer.write("[" + strId + "]" + containerDna.findInIdMap(Dna::getId())->getName() + ":" +
          containerDna.findInIdMap(Dna::getId())->getDna().getAsChar());
    }
    else
    {
        std::string lastDnasequence= (containerDna.findInIdMap(Dna::getId())->getDna()).getAsChar()+containerDna.findInIdMap(Dna::getId())->getDna().length()-3;
        std::string firstDnasequence(containerDna.findInIdMap(Dna::getId())->getDna().getAsChar());
        firstDnasequence = firstDnasequence.substr(0,32);
        writer.write("[" + strId + "]" + containerDna.findInIdMap(Dna::getId())->getName() + ":" + firstDnasequence+"..."+lastDnasequence);

    }

}


