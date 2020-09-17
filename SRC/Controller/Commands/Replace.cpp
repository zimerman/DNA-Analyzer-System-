//
// Created by a on 9/15/20.
//

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

    return (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#')
        && (param.getParam().size() == 4 || (param.getParam().size() > 4 && param.getParam()[param.getParam().size()-1][0]=='@'));
}


void Replace::run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    size_t index = getIndex(param.getParam());
    size_t idDna;
    std::string NewdnaName;

    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
            writer.write("name of DNA not found");
            return;
        }
        idDna = containerDna.findIdByName(param.getParam()[1].substr(1));
    }

    else
    {
        idDna = castToSize(param.getParam()[1].substr(1));
        if(!containerDna.isexistId(idDna))
        {
            writer.write("id of DNA not found");
            return;
        }
    }

    Dnasequence replace_dna = replace(param.getParam(), index, containerDna, idDna);

    if (index == param.getParam().size())
    {
        containerDna.findInIdMap(idDna)->setDnaSequence(replace_dna);
        containerDna.findInIdMap(idDna)->getStatus().setStatus("modified", idDna);
        print(writer,containerDna, idDna);
    }

    else
    {
        NewdnaName = getName(idDna, "_r", containerDna, param.getParam()[index+1]);
        if(NewdnaName.empty())
        {
            writer.write("This name already Exists");
            return;
        }
        Dna* newdna = new Dna(NewdnaName, "new",replace_dna);
        containerDna.addDna(newdna);
        print(writer,containerDna, Dna::getId());
    }
}


void Replace::print(const Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);
    writer.write("[" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar());
}