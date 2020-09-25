#ifndef DNDSEQUENCE_MANAGECOMMAND_H
#define DNDSEQUENCE_MANAGECOMMAND_H
#include <memory>
#include "Commands/Icommand.h"


class Managecommand
{
    public:
         static void initCommands();
         static Icommand* createcommand(const std::string& command);
         static void realase();

    private:
         static std::map<std::string, Icommand*> m_mapCommand;
};



#endif //DNDSEQUENCE_MANAGECOMMAND_H
