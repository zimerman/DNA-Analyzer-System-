#include "Replace.h"
#include "../Auxiliaryfunctions.h"


Dnasequence Replace::replace(const std::vector<std::string>& param,size_t lastIndex,dataDNA& containerDna,size_t idDna)
{
    Dnasequence newDnaseq(containerDna.findInIdMap(idDna)->getDna());

    for(size_t index = 2; index < lastIndex;index += 2)
    {
        newDnaseq.getAsCharNonConst()[castToSize(param[index])] = param[index+1][0];
    }

    return newDnaseq;
}


size_t Replace::getIndex(const std::vector<std::string>& param)
{
    size_t index = 0;

    while(index < param.size() && param[index][0] != ':')
    {
        ++index;
    }

    return index;
}

bool Replace::isValid(const Paramcommand& param) {

    bool isCorrect= true;

    if (param.getParam()[param.getParam().size()-2][0] == ':')
        isCorrect = (param.getParam()[param.getParam().size()-1][0] == '@');

    return (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#') && isCorrect;
}


std::string Replace::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t index = getIndex(param.getParam());
    size_t idDna;
    std::string NewdnaName;
    idDna = getId(containerDna, param.getParam()[1]);

    if(!idDna)
    {
        return "DNA not found";
    }

    Dnasequence replace_dna = replace(param.getParam(), index, containerDna, idDna);

    if (index == param.getParam().size())
    {
        containerDna.findInIdMap(idDna)->setDnaSequence(replace_dna);
        containerDna.findInIdMap(idDna)->getStatus().setStatus("modified", idDna);
        return print(writer,containerDna, idDna);
    }
    else
    {
        NewdnaName = getName(idDna, "_r", containerDna, param.getParam()[index+1]);
        if(NewdnaName.empty())
        {
            return "This name already Exists";
        }
        Dna* newdna = new Dna(NewdnaName, "new",replace_dna);
        containerDna.addDna(newdna);

        return print(writer,containerDna, Dna::getId());
    }
}


std::string Replace::print(Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);

    return "[" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar();
}