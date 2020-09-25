#ifndef DNDSEQUENCE_STATUSDNA_H
#define DNDSEQUENCE_STATUSDNA_H
#include <string>
#include <list>
#include <vector>


class StatusDna
{
    public:
        StatusDna(const std::string& status);
        void setStatus(const std::string& status, size_t id);
        static std::vector<std::string>& getListStatus();
        static std::string& getStatus(size_t idDna);
private:
        std::string m_status;
        static std::vector<std::string> m_statuslist;
};


#endif //DNDSEQUENCE_STATUSDNA_H
