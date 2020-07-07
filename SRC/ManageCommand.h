//
// Created by a on 7/5/20.
//

#ifndef SRC_MANAGECOMMAND_H
#define SRC_MANAGECOMMAND_H
#include "Icommand.h"
#include "Load.h"
class ManageCommand
{
    public:
        static Icommand* createCtorCommand(const ParamCommand& pharams);
};


#endif //SRC_MANAGECOMMAND_H
