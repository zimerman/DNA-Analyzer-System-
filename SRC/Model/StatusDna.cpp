//
// Created by a on 7/5/20.
//

#include <iostream>
#include "StatusDna.h"
std::vector<std::string> StatusDna::m_statuslist(0);
StatusDna::StatusDna(const std::string& status):m_status(status)
{
    m_statuslist.push_back(status);
}

void StatusDna::setStatus(const std::string& status, size_t id)
{
    m_status = status;
    m_statuslist[id-1] = status;
//    for (unsigned int i=0;i<m_statuslist.size();++i)
//    {
//        std::cout<<m_statuslist[i]<<"\n";
//    }
}

std::vector<std::string>& StatusDna::getListStatus()
{
    return m_statuslist;
}




