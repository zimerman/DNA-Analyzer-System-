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
    return params.getParam().size() == 2 || ((params.getParam().size() == 3) && (params.getParam()[2][0] == '@'));
}

Load::Load(const ParamCommand& params)
{
    if(!isValid(params))
    {
        throw std::invalid_argument("\nthis command is not valid to Load");
    }
}

void Load::run(const Iwriter& writer,const ParamCommand& param, DataDNA& containerDna)
{
    FileReaderRwadna myfile(param.getParam()[1]);
    myfile.read();
    std::string name;
    if(param.getParam().size()<3)
    {
        name=param.getParam()[1];
        /*containerDna.find();
        while(containerDna.isExist(containerDna.find(name)))
        {
            containerDna.castToSizet()
        }*/
    }
    else
    {
        if(containerDna.isExist(param.getParam()[2]))
        {
            std::cout<<"There is such a well-known sequence already";
            return;
        }
        name=param.getParam()[2].substr(1);
    }
    if(containerDna.isExist(name))
    {
        std::string result4;
        std::stringstream sstm4;
        sstm4 << containerDna.getNameDna(name)->getCount();
        containerDna.getNameDna(name)->setCount();
        result4 = sstm4.str();
        name = name + "_" + result4;
    }
    DNA* newdna = new DNA(name,"new",myfile);
    containerDna.addDataDNAidtodna(newdna);
    containerDna.addDataDNAnametoid(name);
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


