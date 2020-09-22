//
// Created by a on 9/17/20.
//

#include "Quit.h"
#include "../Auxiliaryfunctions.h"
#include <algorithm>

bool Quit::isValid(const Paramcommand& param)
{
    return param.getParam().size() == 1;
}


std::string Quit::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");
    std::string result;
    size_t countModified = std::count(StatusDna::getListStatus().begin(), StatusDna::getListStatus().end(), "modified");
    size_t countNew = std::count(StatusDna::getListStatus().begin(), StatusDna::getListStatus().end(), "new");
    writer.write("There are " + castToString(countModified) + " modified and " + castToString(countNew) + " new sequences. Are you sure you want to quit?\nPlease confirm by 'y' or 'Y', or cancel by 'n' or 'N'.");
    while(true)
    {
        reader.read();
        result = reader.get();
        if (result == "Y" || result == "y")
        {
            print(writer, "Thank you for using Dnalanyzer.\nGoodbye!");
            return "quit";
//            throw std::exception();
        }
        else if(result == "N" || result == "n")
        {
            break;
        }
        else
        {
            print(writer,"You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.");
        }
    }
    return "";
}


void Quit::print(Iwriter& writer, const std::string& string)
{
    writer.write(string);
}