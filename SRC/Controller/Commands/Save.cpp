#include <sstream>
#include "Save.h"
#include "../Auxiliaryfunctions.h"


bool Save::isValid(const Paramcommand& param)
{
    return ((2==param.getParam().size()||(param.getParam().size()==3&&(param.getParam()[2][0]=='@')))&&(param.getParam()[1][0]=='#'||param.getParam()[1][0]=='@'));
}


std::string Save::save(dataDNA& containerDna, const Paramcommand&param, size_t idDna)
{
    std::string fileDnaName;

    if(param.getParam().size()<3)
    {
        fileDnaName = containerDna.findInIdMap(idDna)->getName()+".rawdna";
    }
    else
    {
        fileDnaName = param.getParam()[2].substr(1)+".rawdna";
    }
    containerDna.findInIdMap(idDna)->getStatus().setStatus("up to date", idDna);

    return fileDnaName;

}


std::string Save::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    std::string fileDnaName;
    size_t idDna;
    idDna = getId(containerDna, param.getParam()[1]);

    if(!idDna)
    {
        return "DNA not found";
    }
    rawDnaWriter myfile(save(containerDna,param, idDna));
    myfile.write(containerDna.findInIdMap(idDna)->getDna().getAsChar());

    return "";
}
