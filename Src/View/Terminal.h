//
// Created by a on 7/7/20.
//

#ifndef DNDSEQUENCE_TERMINAL_H
#define DNDSEQUENCE_TERMINAL_H

#include "Ireader.h"
#include "Iwriter.h"
#include "../Model/dataDNA.h"
#include "UserInterface.h"

class Terminal:public UserInterface{
public:
    int start(const Iwriter& writer, Ireader& reader,dataDNA& containerDna);
};


#endif //DNDSEQUENCE_TERMINAL_H
