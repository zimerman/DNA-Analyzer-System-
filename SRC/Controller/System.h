//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_SYSTEM_H
#define DNDSEQUENCE_SYSTEM_H


#include "../View/Iwriter.h"
#include "../View/Ireader.h"
#include "../View/UserInterface.h"

class System {

public:
    void start(const Iwriter& writer, Ireader& reader,UserInterface* UI);

};


#endif //DNDSEQUENCE_SYSTEM_H
