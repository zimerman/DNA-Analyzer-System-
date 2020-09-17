//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_DATADNA_H
#define DNDSEQUENCE_DATADNA_H

#include <map>
#include "Dna.h"
#include "StatusDna.h"
class dataDNA {
public:
    ~dataDNA();
    void addDna(Dna* newDna);
    void delDna(size_t id);
     //std::map<size_t ,Dna*>& getMap();
     Dna*findInIdMap(size_t);
    Dna*findInNameMap(const std::string& name);
    size_t findIdByName(const std::string& name);
    bool isexistId(size_t);
    bool isexistName(const std::string& name);
    void setName(size_t id, const std::string& newName);
private:
     std::map<size_t ,Dna*> m_mapIdDna;
     std::map<std::string ,size_t> m_mapNameDna;


};


#endif //DNDSEQUENCE_DATADNA_H
