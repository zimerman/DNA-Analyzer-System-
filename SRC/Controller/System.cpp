//
// Created by a on 7/5/20.
//

#include "System.h"
#include "../View/Iwriter.h"
#include "../View/Ireader.h"
#include "../Model/dataDNA.h"
#include "../View/Terminal.h"
#include "stdlib.h"
#include "CallBack.h"
#include "Commands/Icommand.h"
#include "Managecommand.h"

void System::start(Iwriter& writer, Ireader& reader,UserInterface& UI)
{
    dataDNA containerDna;
    Managecommand::initCommands();
    CallBack<System> callback(*this, &System::exucteCommand);
    UI.start(writer,reader,containerDna,callback);
}

std::string System::exucteCommand(Iwriter& writer, Ireader& reader,dataDNA& containerDna, Paramcommand& parameter)
{
    std::string result;
    Icommand *command = Managecommand::createcommand(parameter.getParam()[0]);
    result = command->run(writer, reader, containerDna, parameter);
    return result;
}
