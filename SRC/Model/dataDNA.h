#ifndef DNDSEQUENCE_DATADNA_H
#define DNDSEQUENCE_DATADNA_H
#include <map>
#include "Dna.h"


class dataDNA
{
    public:
        ~dataDNA();
        void addDna(Dna* newDna);
        void delDna(size_t id);
        Dna*findInIdMap(size_t);
        Dna*findInNameMap(const std::string& name);
        size_t findIdByName(const std::string& name);
        bool isexistId(size_t);
        bool isexistName(const std::string& name);
        void setName(size_t id, const std::string& newName);
        std::vector<size_t> getIdsDna();
    private:
         std::map<size_t ,Dna*> m_mapIdDna;
         std::map<std::string ,size_t> m_mapNameDna;
};


#endif //DNDSEQUENCE_DATADNA_H
