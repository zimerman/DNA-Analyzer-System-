//
// Created by a on 7/5/20.
//

#include "DNA.h"
size_t DNA::m_id=0;

DNA::DNA(const std::string& name,const std::string& status,const std::string& dnaSeq):
        m_Dna_seq(dnaSeq),m_name(name),m_status(status)
{
    m_id=++m_id;
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
    return m_Dna_seq.cast_char();
}