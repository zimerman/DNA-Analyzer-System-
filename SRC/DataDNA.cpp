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
