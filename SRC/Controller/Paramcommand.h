#ifndef DNDSEQUENCE_PARAMCOMMAND_H
#define DNDSEQUENCE_PARAMCOMMAND_H
#include <vector>
#include <string>


class Paramcommand
{
    public:
        Paramcommand(std::string str);
        std::vector<std::string> getParam()const;

    private:
        std::vector<std::string> m_vparam;
};


#endif //DNDSEQUENCE_PARAMCOMMAND_H
