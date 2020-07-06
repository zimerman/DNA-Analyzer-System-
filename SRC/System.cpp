//
// Created by a on 7/5/20.
//

#include "System.h"
#include "Icommand.h"
#include "ManageCommand.h"

void System::startApp()
{
    while(1)
    {
        KeyboardReader k;
        ParamCommand paramCommand(k.getData());
        Icommand* icommand = ManageCommand::createCtorCommand(paramCommand);
        KeyBoardWriter key;
        //icommand->run(paramCommand);
        key.write(icommand->run(paramCommand));
    }
}
