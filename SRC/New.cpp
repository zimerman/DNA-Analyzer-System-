//
// Created by a on 7/8/20.
//
#include <sstream>
#include "Load.h"
#include "Ireader.h"
#include "DNA.h"
#include "DataDNA.h"
#include "New.h"
New::New(const ParamCommand& params)
{
    std::cout << "new" << std::endl;
    if(!isValid(params)) {
        throw std::invalid_argument("error in create new");
    }
}

bool New::isValid(const ParamCommand& params)
{
    return true;
}

void New::run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)
{
    static size_t count =0;
    DNA* obj1;
    std::string result;
    if(params.getParam().size()<3)
    {
        std::stringstream sstm;
        sstm << "seq"<< count;
        result = sstm.str();
        count++;
        obj1 = new DNA(result,"new",(params.getParam())[1]);
        containerDna.addDataDNAidtodna(obj1);
        containerDna.addDataDNAnametoid((params.getParam())[1]);
    }
    else
    {
        obj1 = new DNA((params.getParam())[2],"new",(params.getParam())[1]);
        containerDna.addDataDNAidtodna(obj1);
        containerDna.addDataDNAnametoid((params.getParam())[1]);
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