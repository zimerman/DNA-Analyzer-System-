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

const std::string Load::run(const ParamCommand& params)
{
    FileReaderRwadna my_file_dna(params.getParam()[1].c_str());
    DNA* dna;
    if((params.getParam().size())==2)
    {
        dna = new DNA((params.getParam())[1],"new",my_file_dna);
    }
    else
    {
        dna = new DNA((params.getParam())[2],"new",my_file_dna);
    }
    DataDNA::getDataDNAidtodna().insert(std::pair<size_t,DNA*>(DNA::getId(), dna));
    DataDNA::getDataDNAnametoid().insert(std::pair<std::string, size_t>(params.getParam()[1], DNA::getId()));
    return print();
}

const std::string Load::print()
{
    std::string result2;
    std::stringstream sstm2;
    sstm2 << DataDNA::getDataDNAidtodna()[DNA::getId()]->getId();
    result2 = sstm2.str();
    if(DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length()>40)
    {
        std::string str=DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq();
        str = str.substr(0,32);
        return ("\n["+result2+"] " + (DataDNA::getDataDNAidtodna()[DNA::getId()]->getName())+": "+ str + "..." +
                                     DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq()[
                                             DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length() - 3]
                                     + DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq()[
                                             DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length() - 2]
                                     + DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq()[
                                             DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq().length() - 1]+"\n");

    }
    else
    {
        return ("\n["+result2+"] " + (DataDNA::getDataDNAidtodna()[DNA::getId()]->getName()) +": " + DataDNA::getDataDNAidtodna()[DNA::getId()]->getDnaSeq()+"\n");
    }

}


