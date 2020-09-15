//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_MANAGECOMMAND_H
#define DNDSEQUENCE_MANAGECOMMAND_H

#include "Commands/Icommand.h"
#include "Commands/Load.h"
#include "Commands/Dup.h"
#include "Commands/Save.h"
#include "Commands/New.h"
#include "Commands/Slice.h"


class Managecommand{

public:
     Managecommand();
     ~Managecommand();
     Icommand* createcommand(const std::string& command);

private:
     std::map<std::string, Icommand*> m_mapCommand;
};



#endif //DNDSEQUENCE_MANAGECOMMAND_H
