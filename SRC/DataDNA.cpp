//
// Created by a on 7/5/20.
//

#include "DataDNA.h"


/*std::vector<DNA> DataDNA::getDataDNA()
{
    static std::vector<DNA> m_data_dna;
    return m_data_dna;
}
*/

std::map<size_t ,DNA*> DataDNA::getDataDNAidtodna()
{
    static std::map<size_t ,DNA*> m_mapIdDna;
    return m_mapIdDna;
}
std::map<std::string,size_t> DataDNA::getDataDNAnametoid()
{
    static std::map<std::string,size_t> m_mapNameId;
    return m_mapNameId;
}