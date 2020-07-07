//
// Created by a on 7/5/20.
//

#include "ManageCommand.h"

Icommand* ManageCommand::createCtorCommand(const ParamCommand& pharams)
{
    if(pharams.getParam()[0]=="new")
    {
        Icommand* command = new New(pharams);
        return command;
    }
    else// if(pharams.getParam()[0]=="Load")
    {
        Icommand* command = new Load(pharams);
        return command;
    }
}
