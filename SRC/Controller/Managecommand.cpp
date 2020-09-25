#include "Managecommand.h"
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
#include "Commands/Help.h"
#include "Commands/List.h"
#include "Commands/Concat.h"


std::map<std::string, Icommand*> Managecommand::m_mapCommand;


void Managecommand::initCommands()
{
    m_mapCommand.insert(std::pair<std::string, Icommand* >("new",new New));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("load",new Load));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("dup",new Dup));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("save",new Save));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("slice",new Slice));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("replace",new Replace));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("len",new Len));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("del",new Del));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("rename",new Rename));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("find",new Find));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("findall",new FindAll));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("count",new Count));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("quit",new Quit));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("help",new Help));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("list",new List));
    m_mapCommand.insert(std::pair<std::string, Icommand* >("concat",new Concat));

}


Icommand* Managecommand::createcommand(const std::string& command)
{
    std::map<std::string, Icommand*>::iterator indexCommand = m_mapCommand.find(command);

    if(indexCommand!=m_mapCommand.end())
    {
        return indexCommand->second;
    }

    throw std::invalid_argument("command not found");
}

void Managecommand::realase()
{
    std::map<std::string, Icommand*>::iterator iter;

    for(iter = m_mapCommand.begin();iter!=m_mapCommand.end();++iter)
    {
        delete iter->second;
    }
}
