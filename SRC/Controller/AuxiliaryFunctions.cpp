//
// Created by a on 7/8/20.
//

#include <sstream>
#include "AuxiliaryFunctions.h"

std::string castToString(size_t count)
{
    std::string result;
    std::stringstream sstm;
    sstm << count;
    result = sstm.str();
    return result;
}

size_t castToSizet(std::string str)
{
    std::stringstream temp(str);
    size_t id;
    temp >> id;
    return id;
}