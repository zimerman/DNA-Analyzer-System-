#include "System.h"
#include "../View/Terminal.h"
#include "stdlib.h"
#include "CallBack.h"
#include "Managecommand.h"
#include "Commands/Help.h"


void System::start(Iwriter& writer, Ireader& reader,UserInterface& UI)
{
    dataDNA containerDna;
    Managecommand::initCommands();
    Help::initializeMapAbout();
    CallBack<System> callback(*this, &System::exucteCommand);
    UI.start(writer,reader,containerDna,callback);
    Managecommand::realase();
}


std::string System::exucteCommand(Iwriter& writer, Ireader& reader,dataDNA& containerDna, Paramcommand& parameter)
{
    std::string result;
    Icommand* command = Managecommand::createcommand(parameter.getParam()[0]);
    result = command->run(writer, reader, containerDna, parameter);

    return result;
}


void System::turnUp(Iwriter& writer)
{
    writer.write("\n***********Welcome to DnaAlanyzer Sytem***********\n");
}


void System::shutDown(Iwriter& writer)
{
    writer.write("\n***********Sutting down***********");
}