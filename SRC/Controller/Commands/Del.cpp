#include "Del.h"
#include "../Auxiliaryfunctions.h"


std::string Del::deleteDna(dataDNA& containerDna,size_t idDna,Ireader& reader,Iwriter& writer)
{
    std::string result;
    std::string output;
    writer.setColor("\033[1;32m\033[0m");
    writer.write("Do you really want to delete " + containerDna.findInIdMap(idDna)->getName() + ": " +
                 containerDna.findInIdMap(idDna)->getDna().getAsChar() +
                 "?\nPlease confirm by 'y' or 'Y', or cancel by 'n' or 'N'.");

    while(true)
    {
        reader.read();
        result = reader.get();

        if (result == "Y" || result == "y")
        {
            output = print(writer, containerDna, idDna);
            containerDna.findInIdMap(idDna)->getStatus().setStatus("", idDna);
            containerDna.delDna(idDna);
            return output;
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

    idDna = getId(containerDna, param.getParam()[1]);
    if(!idDna)
    {
        return "DNA not found";
    }

    return deleteDna(containerDna,idDna,reader,writer);
}


std::string Del::print(Iwriter& writer, dataDNA& containerDna, size_t idDna)
{
    std::string strId = castToString(idDna);
    return "Deleted: [" +strId+ "]"+ containerDna.findInIdMap(idDna)->getName()+":"+containerDna.findInIdMap(idDna)->getDna().getAsChar();
}