//
// Created by a on 7/5/20.
//

#include "System.h"
#include "Icommand.h"
#include "ManageCommand.h"
#include "Ireader.h"

void System::startApp()
{
    while(1)
    {
        KeyboardReader k;
        ParamCommand paramCommand(k.getData());
        Icommand* icommand = ManageCommand::createCtorCommand(paramCommand);
        KeyBoardWriter key;
        key.write(icommand->run(paramCommand));
    }
}
