//
// Created by a on 7/8/20.
//
#include <sstream>
#include "Load.h"
#include "Ireader.h"
#include "DNA.h"
#include "DataDNA.h"
#include "New.h"
#include "AuxiliaryFunctions.h"
New::New(const ParamCommand& params)
{
    std::cout << "new" << std::endl;
    if(!isValid(params)) {
        throw std::invalid_argument("\nthis command is not valid to new\n");
    }
}

bool New::isValid(const ParamCommand& params)
{
    return params.getParam().size() == 2 || ((params.getParam().size() == 3) && (params.getParam()[2][0] == '@'));
}

void New::run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)
{
    static size_t count =1;
    DNA* obj1;
    std::string name;
    if(params.getParam().size()<3)
    {
        name = "seq"+ castToString(count);
        count++;
        while(containerDna.isExist(name))
        {
            ++count;
            name = "seq"+ castToString(count);
        }
        obj1 = new DNA(name,"new",(params.getParam())[1]);
        containerDna.addDataDNAidtodna(obj1);
        containerDna.addDataDNAnametoid((params.getParam())[1]);
    }
    else
    {
        if((containerDna.isExist(params.getParam()[2])))
        {
            std::cout<<"this name of sequence exsist";
            return;
        }
        obj1 = new DNA((params.getParam())[2].substr(1),"new",(params.getParam())[1]);
        containerDna.addDataDNAidtodna(obj1);
        containerDna.addDataDNAnametoid((params.getParam())[2]);
    }
    print(writer, containerDna);
}

void New::print(const Iwriter& writer,DataDNA& containerDna)
{
    std::string result2;
    std::stringstream sstm2;
    sstm2 << containerDna.getDataDNAidtodna()[DNA::getId()]->getId();
    result2 = sstm2.str();
    writer.write("["+result2+"]"+containerDna.getDataDNAidtodna()[DNA::getId()]->getName() +": " + containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()+"\n");
}