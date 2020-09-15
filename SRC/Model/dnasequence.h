//
// Created by a on 6/1/20.
//

#ifndef DNAPROJECT_DNASEQUENCE_H
#define DNAPROJECT_DNASEQUENCE_H
#include <string>
#include <ostream>
#include <list>
#include <fstream>
#include <iostream>
#include "Ireader.h"
#include "Iwriter.h"

class DnaSequence {
private:
    class Nucleotide
    {
    public:
        Nucleotide();
        Nucleotide(char c);
        Nucleotide& operator=(char c);
        char get_c()const;
        operator char(){
            return m_c;
        }
        const Nucleotide match_pair();
    private:
        char m_c;
        bool check_validation_nucleotide(const char str);
    };
public:
    DnaSequence(const Ireader& obj);
    DnaSequence(const std::string& str);
    //DnaSequence(const char* str);
    DnaSequence(const DnaSequence& obj);
    DnaSequence(size_t len);
    ~DnaSequence();
    void init(const char* str);
    const char* getString()const;
    DnaSequence& operator=(const DnaSequence& obj);
    size_t length()const;
    const char* cast_char()const;
    Nucleotide& operator[](size_t index)const;
    friend std::ostream& operator <<(std::ostream& cout, const DnaSequence& obj);
    DnaSequence slice(size_t start, size_t en);
    DnaSequence pairing();
    size_t find(const DnaSequence& sub_dna);
    size_t count(const DnaSequence& sub_dna);
    std::list<size_t> findAll(const DnaSequence& sub_dna);
    std::list<size_t> FindConsensusSequences();
    void write(const Iwriter& dna);
private:
    Nucleotide* m_cstring_dna;
    size_t m_len_string_dna;
    bool check_validation(const char* str);
};

bool operator==(const DnaSequence& obj1, const DnaSequence& obj2);
bool operator!=(const DnaSequence& obj1, const DnaSequence& obj2);

#endif //DNAPROJECT_DNASEQUENCE_H
