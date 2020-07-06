//
// Created by a on 7/5/20.
//
#include <sstream>
#include "Icommand.h"

size_t New::m_numName=1;
Icommand::Icommand() {}
New::New(const ParamCommand& params)
{
    if(!isValid(params)) {
        throw std::invalid_argument("error in new");
    }
}

bool New::isValid(const ParamCommand& params)
{
    return true;
}

const char* New::run(const ParamCommand& params)
{
    DNA* obj1;
    std::string result;
    if(params.getParam().size()<3)
    {
        std::stringstream sstm;
        sstm << "seq"<< New::getNumName();
        result = sstm.str();
        m_numName++;
        obj1 = new DNA(result,"new",(params.getParam())[1]);
        DataDNA::getDataDNAidtodna().insert(std::pair<size_t,DNA*>(DNA::getId(),obj1));
        DataDNA::getDataDNAnametoid().insert(std::pair<std::string, size_t>((params.getParam())[1],DNA::getId()));
    }
    else
    {
        obj1 = new DNA((params.getParam())[2],"new",(params.getParam())[1]);
        DataDNA::getDataDNAidtodna().insert(std::pair<size_t,DNA*>(DNA::getId(), obj1));
        DataDNA::getDataDNAnametoid().insert(std::pair<std::string, size_t>(((params.getParam())[1]), DNA::getId()));
        //result=obj1->getName();
    }
    std::string result2;
    std::stringstream sstm2;
    sstm2 << DNA::getId();
    result2 = sstm2.str();
    return ("[" + result2 + "] "+ obj1->getName() +" "+ std::string(obj1->getDnaSeq())+"\n").c_str();
}

size_t New::getNumName()
{
    return m_numName;
}
