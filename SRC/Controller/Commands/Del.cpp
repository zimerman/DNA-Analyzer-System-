//
// Created by a on 9/16/20.
//

#include "Del.h"
#include "../Auxiliaryfunctions.h"

std::string Del::deleteDna(dataDNA& containerDna,size_t idDna,Ireader& reader,Iwriter& writer)
{
    std::string result;
    writer.write("Do you really want to delete " + containerDna.findInIdMap(idDna)->getName() + ": " +
                 containerDna.findInIdMap(idDna)->getDna().getAsChar() +
                 "?\nPlease confirm by 'y' or 'Y', or cancel by 'n' or 'N'.");
    while(true)
    {
        reader.read();
        result = reader.get();
        if (result == "Y" || result == "y")
        {
            return print(writer, containerDna, idDna);
            containerDna.delDna(idDna);
            break;
        }
        else if(result == "N" || result == "n")
        {
            break;
        }
        else
        {
            writer.write("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.");
        }
    }
    return "";
}


bool Del::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 2 && (param.getParam()[1][0] == '@' || param.getParam()[1][0] == '#');
}


std::string Del::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    size_t idDna;
    if(param.getParam()[1][0]=='@')
    {
        if(!containerDna.isexistName(param.getParam()[1].substr(1)))
        {
//            writer.write("name of DNA not found");
//            return;
            return "name of DNA not found";
        }
        idDna = containerDna.findIdByName(param.getParam()[1].substr(1));
    }

    else
    {
        idDna = castToSize(param.getParam()[1].substr(1));
        if(!containerDna.isexistId(idDna))
        {
//            writer.write("id of DNA not found");
//            return;
            return "id of DNA not found";
        }
    }
    return deleteDna(containerDna,idDna,reader,writer);
//    return "";
}


std::string Del::print(Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);
//    writer.write("Deleted: [" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar());
    return "Deleted: [" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar();

}