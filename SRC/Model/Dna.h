//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_DNA_H
#define DNDSEQUENCE_DNA_H


#include <string>
#include "dnasequence.h"
#include "StatusDna.h"
class Dna {
public:
    Dna(const std::string&  name, const std::string&  status, const Dnasequence& dnasequence);
    ~Dna();
    const static size_t getId();
    const std::string& getName();
    const Dnasequence& getDna();
    const size_t getCountName()const;
    size_t setCountName();
    StatusDna getStatus();
    void setDnaSequence(const Dnasequence& dnasequence);
private:
    Dnasequence* m_Dna;
    std::string m_name;
    StatusDna m_status;
    static size_t m_id;
    size_t m_countName;

};
inline const size_t Dna::getId()
{
    return m_id;
}
inline const std::string& Dna::getName()
{
    return m_name;
}
inline const Dnasequence& Dna::getDna()
{
    return *m_Dna;
}
inline const size_t Dna::getCountName()const
{
    return m_countName;
}

#endif //DNDSEQUENCE_DNA_H
