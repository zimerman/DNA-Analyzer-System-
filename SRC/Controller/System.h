#ifndef DNDSEQUENCE_SYSTEM_H
#define DNDSEQUENCE_SYSTEM_H
#include "../View/Iwriter.h"
#include "../View/Ireader.h"
#include "Paramcommand.h"
#include "Managecommand.h"

class UserInterface;
class dataDNA;


class System
{
    public:
        void start(Iwriter& writer, Ireader& reader,UserInterface& UI);
        std::string exucteCommand(Iwriter& writer, Ireader& reader,dataDNA& containerDna, Paramcommand& parameter);
        void turnUp(Iwriter& writer);
        void shutDown(Iwriter& writer);
};


#endif //DNDSEQUENCE_SYSTEM_H
