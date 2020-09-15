//
// Created by a on 7/8/20.
//

#include <cstddef>
#include <sstream>
#include "string"
#include "Auxiliaryfunctions.h"
size_t castToSize(std::string string)
{
    std::stringstream temp(string);
    size_t idDna;
    temp>> idDna;
    return idDna;

}

std::string castToString(size_t num)
{

    std::stringstream temp;
    temp<<num;
    return temp.str();
}