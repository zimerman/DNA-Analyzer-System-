#include "Concat.h"
#include "../Auxiliaryfunctions.h"


std::string Concat::getNewName(std::vector<size_t> idsDna, dataDNA& containerDna,const std::string& paramater)
{
    size_t count = 1;
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

        if (idsDna.size() == 2)
        {
            NewdnaName = containerDna.findInIdMap(idsDna[0])->getName() + "_" + containerDna.findInIdMap(idsDna[1])->getName() + "_c" + castToString(count);
            count++;

            while(containerDna.isexistName(NewdnaName))
            {
                NewdnaName = containerDna.findInIdMap(idsDna[0])->getName() + "_" + containerDna.findInIdMap(idsDna[1])->getName() + "_c" + castToString(count);
                count++;
            }
        }
        else
        {
            NewdnaName = "conseq_" + castToString(count);
            count++;

            while (containerDna.isexistName(NewdnaName))
            {
                NewdnaName = "conseq_" + castToString(count);
                count++;
            }
        }
    }

    return NewdnaName;
}


bool Concat::isValid(const Paramcommand& param)
{
    bool isCorrect= true;

    if (param.getParam()[param.getParam().size()-2][0] == ':')
        isCorrect = (param.getParam()[param.getParam().size()-1][0] == '@');

    return (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#') && isCorrect;
}


size_t Concat::getIndex(const std::vector<std::string>& param)
{
    size_t index = 0;

    while(index < param.size() && param[index][0] != ':')
    {
        ++index;
    }

    return index;
}


Dnasequence Concat::concat(std::vector<size_t> idsDna, size_t lastIndex,dataDNA& containerDna)
{
    std::string dnaConcat;

    for(size_t index = 1; index < lastIndex; ++index)
    {
        dnaConcat += std::string(containerDna.findInIdMap(idsDna[index-1])->getDna().getAsChar());
    }

    return Dnasequence(dnaConcat);
}


std::vector<size_t> Concat::getIds(size_t lastIndex, dataDNA& containerDna,std::vector<std::string> param)
{
    size_t idDna;
    std::vector<size_t> vecIds;

    for(size_t index = 1; index < lastIndex; ++index)
    {
        idDna = getId(containerDna, param[index]);

        if(!idDna)
        {
            vecIds.clear();
            break;
        }
        vecIds.push_back(idDna);
    }

    return vecIds;
}


std::string Concat::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t lastIndex = getIndex(param.getParam());
    std::string NewdnaName;
    std::vector<size_t> idsDna = getIds(lastIndex, containerDna, param.getParam());

    if (idsDna.empty())
    {
        return "DNA not found";
    }
    Dnasequence concat_dna = concat(idsDna, lastIndex, containerDna);

    if (lastIndex == param.getParam().size())
    {
        containerDna.findInIdMap(idsDna[0])->setDnaSequence(concat_dna);
        containerDna.findInIdMap(idsDna[0])->getStatus().setStatus("modified", idsDna[0]);
        return print(writer,containerDna, idsDna[0]);
    }
    else
    {
        NewdnaName = getNewName(idsDna, containerDna, param.getParam()[lastIndex+1]);

        if(NewdnaName.empty())
        {
            return "This name already Exists";
        }
        Dna* newdna = new Dna(NewdnaName, "new",concat_dna);
        containerDna.addDna(newdna);

        return print(writer,containerDna, Dna::getId());
    }
}


std::string Concat::print(Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);

    return "[" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar();
}