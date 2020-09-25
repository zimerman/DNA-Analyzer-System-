#include "dataDNA.h"


void dataDNA::addDna(Dna* newDna)
{
    m_mapIdDna.insert(std::pair<size_t, Dna*>(Dna::getId(),newDna));
    m_mapNameDna.insert(std::pair<std::string, size_t>(newDna->getName(), Dna::getId()));

}


void dataDNA::delDna(size_t id)
{
    m_mapNameDna.erase(m_mapIdDna[id]->getName());
    delete m_mapIdDna[id];
    m_mapIdDna[id] = NULL;
    m_mapIdDna.erase(id);
}


dataDNA::~dataDNA()
{
    std::map<size_t, Dna*>::iterator iter;

    for(iter = m_mapIdDna.begin();iter!=m_mapIdDna.end();++iter)
    {
        delete iter->second;
    }
}


Dna*dataDNA::findInIdMap(size_t id)
{
    return m_mapIdDna[id];
}


Dna*dataDNA::findInNameMap(const std::string& name)
{
    return m_mapIdDna[m_mapNameDna[name]];
}


bool dataDNA::isexistName(const std::string& name)
{
    return m_mapNameDna.find(name)!=m_mapNameDna.end();

}

bool dataDNA::isexistId(size_t id)
{
    return m_mapIdDna.find(id)!=m_mapIdDna.end();

}


size_t dataDNA::findIdByName(const std::string& name)
{
    return m_mapNameDna[name];
}


void dataDNA::setName(size_t id, const std::string& newName)
{
    m_mapNameDna.erase(m_mapIdDna[id]->getName());
    m_mapNameDna[newName] = id;
    m_mapIdDna[id]->setName(newName);
}


std::vector<size_t> dataDNA::getIdsDna()
{
    std::vector<size_t> vecIds;
    std::map<size_t ,Dna*>::iterator iter;
    for(iter = m_mapIdDna.begin();iter!=m_mapIdDna.end();++iter)
    {
        vecIds.push_back(iter->first);
    }

    return vecIds;
}