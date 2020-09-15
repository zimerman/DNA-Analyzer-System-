//
// Created by a on 7/5/20.
//
#include "DataDNA.h"

std::map<size_t ,DNA*>& DataDNA::getDataDNAidtodna()
{
    return m_mapIdDna;
}

void DataDNA::addDataDNAidtodna(DNA* dna)
{
    m_mapIdDna.insert(std::pair<size_t,DNA*>(DNA::getId(), dna));
}

void DataDNA::addDataDNAnametoid(std::string name)
{
    m_mapNameId.insert(std::pair<std::string, size_t>(name,DNA::getId()));
}

DNA* DataDNA::find(size_t id)
{
    return m_mapIdDna[id];
}

bool DataDNA::isExist(std::string name)
{
    std::cout<<"555"<<name<<"%%5";
    std::cout<<"Boool:"<<(m_mapNameId.find(name) != m_mapNameId.end())<<"\n";
    return (m_mapNameId.find(name) != m_mapNameId.end());
}

bool DataDNA::isExistId(size_t id)
{
    return (m_mapIdDna.find(id) != m_mapIdDna.end());
}

DNA* DataDNA::getNameDna(std::string name)
{
    return m_mapIdDna[m_mapNameId[name]];
}

