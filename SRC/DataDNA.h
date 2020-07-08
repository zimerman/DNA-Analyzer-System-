//
// Created by a on 7/5/20.
//

#ifndef CODE_DATADNA_H
#define CODE_DATADNA_H

#include <map>
#include <vector>
#include "DNA.h"
class DataDNA
{
    public:
        void addDataDNAidtodna(DNA* size_t);
        void addDataDNAnametoid(std::string name);
        std::map<size_t ,DNA*>& getDataDNAidtodna();
        DNA* find(size_t id);
    private:
        std::map<size_t ,DNA*> m_mapIdDna;
        std::map<std::string,size_t> m_mapNameId;
};


#endif //CODE_DATADNA_H
