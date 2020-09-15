//
// Created by a on 7/5/20.
//

#include "Dna.h"

#include <utility>
size_t Dna::m_id = 0;
Dna::Dna(const std::string&  name, const std::string&  status, const Dnasequence& dnasequence):m_Dna(new Dnasequence(dnasequence)),m_name(name),m_status(status),m_countName(1)
{
    ++m_id;
}

Dna::~Dna()
{
    delete m_Dna;
}

size_t Dna::setCountName()
{
    return m_countName++;
}

StatusDna Dna::getStatus()
{
    return m_status;
}

void Dna::setDnaSequence(const Dnasequence& dnasequence)
{
    *m_Dna = dnasequence;
}
