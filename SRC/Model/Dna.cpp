//
// Created by a on 7/5/20.
//

#include "DNA.h"
size_t DNA::m_id=0;

DNA::DNA(const std::string& name,const std::string& status,const DnaSequence& dnaSeq):
        m_Dna_seq(new DnaSequence(dnaSeq)),m_name(name),m_status(status),m_count(1)
{
    ++m_id;
}

size_t DNA::getId()
{
    return m_id;
}

std::string DNA::getName()
{
    return m_name;
}

std::string DNA::getDnaSeq()
{
    return m_Dna_seq->cast_char();
}

DnaSequence* DNA::getDnaSeq2()
{
    return m_Dna_seq;
}

size_t DNA::getCount()const
{
    return m_count;
}

void DNA::setCount()
{
    ++m_count;
}

Status& DNA::getStatus()
{
    return m_status;
}

