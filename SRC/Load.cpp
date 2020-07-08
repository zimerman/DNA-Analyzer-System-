//
// Created by a on 7/6/20.
//

#include <sstream>
#include "Load.h"
#include "Ireader.h"
#include "DNA.h"
#include "DataDNA.h"

bool Load::isValid(const ParamCommand& params)
{
    return true;
}

Load::Load(const ParamCommand& params)
{
    if(!isValid(params))
    {
        throw std::invalid_argument("error in Load");
    }
}

void Load::run(const Iwriter& writer,const ParamCommand& param, DataDNA& containerDna)
{
    FileReaderRwadna myfile(param.getParam()[1]);
    myfile.read();
    if(param.getParam().size()<3)
    {
        DNA* newdna = new DNA(param.getParam()[1],"new",myfile);
        containerDna.addDataDNAidtodna(newdna);
    }
    else
    {
        DNA* newdna = new DNA(param.getParam()[2],"new",myfile);
        containerDna.addDataDNAidtodna(newdna);
        containerDna.addDataDNAnametoid((param.getParam())[2]);

    }
    print(writer,containerDna);

}

void Load::print(const Iwriter& writer,DataDNA& containerDna)
{
    std::string result2;
    std::stringstream sstm2;
    sstm2 << containerDna.getDataDNAidtodna()[DNA::getId()]->getId();
    result2 = sstm2.str();
    if(containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length()>40)
    {
        std::string str=containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq();
        str = str.substr(0,32);
        writer.write("\n["+result2+"] " + (containerDna.getDataDNAidtodna()[DNA::getId()]->getName())+": "+ str + "..." +
                containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()[
                containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length() - 3]
                 + containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()[
                containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length() - 2]
                + containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()[
                containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length() - 1]+"\n");
    }
    else
    {
        writer.write("\n["+result2+"] " + (containerDna.getDataDNAidtodna()[DNA::getId()]->getName()) +": " + containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()+"\n");
    }
}


