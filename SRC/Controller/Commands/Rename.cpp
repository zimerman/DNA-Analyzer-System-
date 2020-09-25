#include "Rename.h"
#include "../Auxiliaryfunctions.h"


bool Rename::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 3 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#') && param.getParam()[2][0] == '@';
}


std::string Rename::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t idDna;
    idDna = getId(containerDna, param.getParam()[1]);

    if(!idDna)
    {
        return "DNA not found";
    }
    containerDna.setName(idDna, param.getParam()[2].substr(1));
    containerDna.findInIdMap(idDna)->getStatus().setStatus("modified", idDna);

    return "";
}

