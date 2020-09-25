#include <stdexcept>
#include <sstream>
#include "Icommand.h"
#include "../../Model/dataDNA.h"
#include "../Auxiliaryfunctions.h"


std::string Ichange::getName(size_t idDna, const std::string& suffix, dataDNA& containerDna,const std::string& paramater)
{
    std::string NewdnaName;

    if (paramater!="@@")
    {
        NewdnaName = paramater.substr(1);

        if(containerDna.isexistName(NewdnaName))
        {
            return "";
        }
    }
    else
    {
        NewdnaName = containerDna.findInIdMap(idDna)->getName() + suffix +
                     castToString(containerDna.findInIdMap(idDna)->getCountName());
        containerDna.findInIdMap(idDna)->setCountName();

        while(containerDna.isexistName(NewdnaName))
        {
            NewdnaName = containerDna.findInIdMap(idDna)->getName()+suffix+castToString(containerDna.findInIdMap(idDna)->getCountName());
            containerDna.findInIdMap(idDna)->setCountName();
        }
    }

    return NewdnaName;
}


size_t Icommand::getId(dataDNA& containerDna, std::string& dna)
{
    size_t idDna = 0;

    if(dna[0]=='@')
    {

        if(!containerDna.isexistName(dna.substr(1)))
        {
            return 0;
        }
        idDna = containerDna.findIdByName(dna.substr(1));
    }
    else if(dna[0]=='#')
    {
        idDna = castToSize(dna.substr(1));

        if(!containerDna.isexistId(idDna))
        {
            return 0;
        }
    }

    return idDna;
}