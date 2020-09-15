//
// Created by a on 9/14/20.
//
#include "../Auxiliaryfunctions.h"
#include "Slice.h"
#include "../../Model/dnasequence.h"
bool Slice::isValid(const Paramcommand& param)
{
    return 4==param.getParam().size() && ((param.getParam()[1][0]=='@') || (param.getParam()[1][0]=='#'));
}


void Slice::run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    size_t from_ind = castToSize(param.getParam()[2]);
    size_t to_ind = castToSize(param.getParam()[3]);
    size_t idDna;
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
            std::cout<<"name of DNA not found";
            return;
        }
        idDna = containerDna.findIdByName(param.getParam()[1].substr(1));
    }
    else
    {
        idDna = castToSize(param.getParam()[1].substr(1));
        if(!containerDna.isexistId(idDna))
        {
            std::cout<<"id of DNA not found";
            return;
        }
    }
    Dnasequence slice_dna = containerDna.findInIdMap(idDna)->getDna().slice(from_ind,to_ind+1);
    std::cout<<slice_dna;
    containerDna.findInIdMap(idDna)->setDnaSequence(slice_dna);
    containerDna.findInIdMap(idDna)->getStatus().setStatus("modified", idDna);
    print(writer,containerDna, idDna);
}



void Slice::print(const Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);
    writer.write("[" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar());
}