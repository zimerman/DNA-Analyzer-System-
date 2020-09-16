//
// Created by a on 6/1/20.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H


#include <string>
#include <iostream>
#include <vector>
#include "list"
#include <fstream>
#include "../View/Ireader.h"
#include "../View/Iwriter.h"

class Dnasequence {

private:

    class Nucleotied{

    public:

        Nucleotied(char c);

        Nucleotied();

        Nucleotied& operator=(char c);

        operator char(){ return m_c;}

        const char getChar()const;

        Nucleotied match();

    private:

        char m_c;

        bool isValideChar(char c);

    };
    void checkEndCodon(size_t index,std::list<Dnasequence >& ConsensusSequence,
            std::list<size_t> endList);

    bool isValid(const char* str);

    void init(const char* cString);

    explicit Dnasequence(size_t);

    Nucleotied* m_cstringDna;

    size_t m_lenCstringDna;

public:

    //Dnasequence(const char* cString);

    Dnasequence(const std::string& cString);

    Dnasequence(const Dnasequence& obj);

    Dnasequence(const Ireader& obj);

    ~Dnasequence();

    Dnasequence& operator=(const Dnasequence& obj);

    friend std::ostream& operator <<(std::ostream& cout,const Dnasequence &str1);

    size_t length()const;

    Nucleotied& operator[](size_t index)const;

    const char* getAsChar()const;

    char* getAsCharNonConst();

    Dnasequence slice(size_t , size_t)const ;

    Dnasequence pairingDna();

    size_t find(const Dnasequence &obj,size_t index=0);

    std::list<size_t > findall(const Dnasequence &obj);

    size_t count(const Dnasequence &obj);

    std::list<Dnasequence> consensus();

    void write(const Iwriter& obj);

};



bool operator==(const Dnasequence&, const Dnasequence&);
bool operator!=(const Dnasequence& ,const Dnasequence&);


#endif //DNA_DNASEQUENCE_H
