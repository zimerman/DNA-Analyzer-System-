//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_STATUSDNA_H
#define DNDSEQUENCE_STATUSDNA_H


#include <string>
#include <list>
#include <vector>

class StatusDna {
public:
    StatusDna(const std::string& status);
    void setStatus(const std::string& status, size_t id);
private:
    std::string m_status;
    static std::vector<std::string> m_statuslist;
};


#endif //DNDSEQUENCE_STATUSDNA_H
