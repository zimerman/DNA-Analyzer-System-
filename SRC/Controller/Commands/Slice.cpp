#include "../Auxiliaryfunctions.h"
#include "Slice.h"


bool Slice::isValid(const Paramcommand& param)
{
    return (((4==param.getParam().size()) || (6==param.getParam().size() && param.getParam()[4][0]==':' && param.getParam()[5][0]=='@'))&& ((param.getParam()[1][0]=='@') || (param.getParam()[1][0]=='#')));
}


std::string Slice::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    size_t from_ind = castToSize(param.getParam()[2]);
    size_t to_ind = castToSize(param.getParam()[3]);
    size_t idDna;
    std::string NewdnaName;
    idDna = getId(containerDna, param.getParam()[1]);

    if(!idDna)
    {
        return "DNA not found";
    }
    Dnasequence slice_dna = containerDna.findInIdMap(idDna)->getDna().slice(from_ind,to_ind+1);

    if(param.getParam().size() < 5)
    {
        containerDna.findInIdMap(idDna)->setDnaSequence(slice_dna);
        containerDna.findInIdMap(idDna)->getStatus().setStatus("modified", idDna);
        return print(writer,containerDna, idDna);
    }
    else
    {
        NewdnaName = getName(idDna, "_s", containerDna, param.getParam()[5]);
        if(NewdnaName.empty())
        {
            return "This name already Exists";
        }
        Dna* newdna = new Dna(NewdnaName, "new",slice_dna);
        containerDna.addDna(newdna);
        return print(writer,containerDna, Dna::getId());
    }
}



std::string Slice::print(Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);
    return "[" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar();
}