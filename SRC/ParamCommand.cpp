//
// Created by a on 7/5/20.
//

#include <vector>
#include "ParamCommand.h"
#include <string>

const std::vector<std::string>& ParamCommand::getParam()const
{
    return m_param_vec;
}

ParamCommand::ParamCommand(std::string phrase)
{
    size_t pos = 0;
    std::string token;
    while ((pos = phrase.find(' ')) != std::string::npos)
    {
        token = phrase.substr(0, pos);
        m_param_vec.push_back(token);
        phrase.erase(0, pos + 1);
    }
    m_param_vec.push_back(phrase);
}

