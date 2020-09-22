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
#include "Commands/Replace.h"
#include "Commands/Len.h"
#include "Commands/Del.h"
#include "Commands/Rename.h"
#include "Commands/Find.h"
#include "Commands/FindAll.h"
#include "Commands/Count.h"
#include "Commands/Quit.h"


class Managecommand{

public:
//     Managecommand();
//     ~Managecommand();
     static void initCommands();
     static Icommand* createcommand(const std::string& command);

private:
     static std::map<std::string, Icommand*> m_mapCommand;
};



#endif //DNDSEQUENCE_MANAGECOMMAND_H
