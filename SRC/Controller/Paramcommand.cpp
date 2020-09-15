//
// Created by a on 7/5/20.
//

#include <iostream>
#include "Paramcommand.h"

Paramcommand::Paramcommand(std::string str)
{

    size_t pos = 0;
    std::string token;
    while ((pos = str.find(' ')) != std::string::npos)
    {
        token = str.substr(0, pos);
        m_vparam.push_back(token);
        str.erase(0, pos + 1);
    }
    m_vparam.push_back(str);
}

std::vector<std::string> Paramcommand::getParam()const
{
    return m_vparam;
}

