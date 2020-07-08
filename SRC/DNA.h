//
// Created by a on 7/5/20.
//

#ifndef CODE_DNA_H
#define CODE_DNA_H
#include "DnaSequence.h"
#include "string.h"
#include "Status.h"
class DNA
{
    public:
        DNA(const std::string& name,const std::string& status,const DnaSequence& dnaSeq);
        static size_t getId();
        std::string getName();
        std::string getDnaSeq();
        DnaSequence& getDnaSeq2();
    private:
        DnaSequence m_Dna_seq;
        static size_t m_id;
        std::string m_name;
        Status m_status;
};


#endif //CODE_DNA_H
