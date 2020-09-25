#include "List.h"
#include <vector>
#include <algorithm>
#include "../Auxiliaryfunctions.h"


bool List::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 1;
}


std::string List::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    std::string listDna;
    std::string prefix;
    std::vector<size_t> listIdDna = containerDna.getIdsDna();
    std::sort(listIdDna.begin(), listIdDna.end());
    std::vector<size_t>::iterator iter;
    std::string status;
    std::string sequence;
    size_t len;

    if(listIdDna.empty())
    {
        return "There are no DNA sequences";
    }

    for (iter = listIdDna.begin(); iter < listIdDna.end(); iter++)
    {
        status = StatusDna::getListStatus()[*iter-1];

        if (status == "new")
        {
            prefix = "o ";
        }
        else if (status == "modified")
        {
            prefix = "* ";
        }
        else
        {
            prefix = "- ";
        }
        sequence = std::string(containerDna.findInIdMap(*iter)->getDna().getAsChar());
        len = containerDna.findInIdMap(*iter)->getDna().length();
        if (len > 40)
        {
            sequence = std::string(containerDna.findInIdMap(*iter)->getDna().getAsChar()).substr(0,37) + "..." + std::string(containerDna.findInIdMap(*iter)->getDna().getAsChar()).substr(len - 4);
        }
        listDna += prefix + "[" + castToString(*iter) + "] " + containerDna.findInIdMap(*iter)->getName() + ": " + sequence + "\n";
    }

    return listDna;
}
