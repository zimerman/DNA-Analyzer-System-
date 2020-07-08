//
// Created by a on 7/7/20.
//

#include <sstream>
#include "Dup.h"

bool Dup::isValid(const ParamCommand& params)
{
    return true;
}

Dup::Dup(const ParamCommand& params)
{
    if(!isValid(params))
    {
        throw std::invalid_argument("error in Load");
    }
}

void Dup::run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)
{
    static size_t count=1;
    DNA* obj1;
    std::string name = ((params.getParam())[1]).substr(1);
    std::stringstream temp(name);
    size_t id;
    temp >> id;
    if(params.getParam().size()<3)
    {
        std::string result;
        std::stringstream sstm;
        sstm << "_"<< count;
        result = sstm.str();
        count++;
        obj1 = new DNA(containerDna.find(id)->getName()+result,"new",containerDna.find(id)->getDnaSeq());
        containerDna.addDataDNAidtodna(obj1);
        containerDna.addDataDNAnametoid(containerDna.find(id)->getName());
    }
    else
    {
        obj1 = new DNA((params.getParam())[2],"new",containerDna.find(id)->getDnaSeq());
        containerDna.addDataDNAidtodna(obj1);
        containerDna.addDataDNAnametoid((params.getParam())[2]);
    }
    print(writer, containerDna);
}

void Dup::print(const Iwriter& writer,DataDNA& containerDna)
{
    std::string result2;
    std::stringstream sstm2;
    sstm2 << containerDna.getDataDNAidtodna()[DNA::getId()]->getId();
    result2 = sstm2.str();
    writer.write("\n["+result2+"] " +containerDna.find(DNA::getId())->getName() + ": "+containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()+"\n");
}
