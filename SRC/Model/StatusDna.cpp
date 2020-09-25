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
}


std::vector<std::string>& StatusDna::getListStatus()
{
    return m_statuslist;
}


std::string& StatusDna::getStatus(size_t idDna)
{
    return m_statuslist[idDna];
}



