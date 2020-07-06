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
    static std::map<size_t ,DNA*>getDataDNAidtodna();
    static std::map<std::string,size_t>getDataDNAnametoid();
private:
};


#endif //CODE_DATADNA_H
