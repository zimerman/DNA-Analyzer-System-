//
// Created by a on 7/7/20.
//

#ifndef SRC_STATUS_H
#define SRC_STATUS_H

#include <string>
#include <list>

class Status {
public:
    Status(std::string str);
private:
    std::string m_status;
    std::list<std::string> m_list_status;
};


#endif //SRC_STATUS_H
