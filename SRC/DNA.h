//
// Created by a on 7/5/20.
//

#ifndef CODE_DNA_H
#define CODE_DNA_H
#include "DnaSequence.h"
#include "string.h"

class DNA
{
public:
    DNA(const std::string& name,const std::string& status,const std::string& dnaSeq);
    static size_t getId();
    std::string getName()const;
private:
    DnaSequence m_Dna_seq;
    static size_t m_id;
    std::string m_name;
    std::string m_status;
};


#endif //CODE_DNA_H
