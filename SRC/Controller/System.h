//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_SYSTEM_H
#define DNDSEQUENCE_SYSTEM_H


#include "../View/Iwriter.h"
#include "../View/Ireader.h"
//#include "../View/UserInterface.h"
#include "Paramcommand.h"
class UserInterface;
class dataDNA;

class System {
public:
    void start(Iwriter& writer, Ireader& reader,UserInterface& UI);
    std::string exucteCommand(Iwriter& writer, Ireader& reader,dataDNA& containerDna, Paramcommand& parameter);

};


#endif //DNDSEQUENCE_SYSTEM_H
