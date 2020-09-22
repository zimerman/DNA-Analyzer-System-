//
// Created by a on 7/5/20.
//

#include "Managecommand.h"
#include <stdlib.h>
//#include <string.h>

//Managecommand::Managecommand()
//{
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("new",new New()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("load",new Load()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("dup",new Dup()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("save",new Save()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("slice",new Slice()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("replace",new Replace()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("len",new Len()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("del",new Del()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("rename",new Rename()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("find",new Find()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("findall",new FindAll()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("count",new Count()));
//    m_mapCommand.insert(std::pair<std::string, Icommand*>("quit",new Quit()));
//
//}
std::map<std::string, Icommand*> Managecommand::m_mapCommand;
void Managecommand::initCommands()
{
    m_mapCommand.insert(std::pair<std::string, Icommand*>("new",new New()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("load",new Load()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("dup",new Dup()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("save",new Save()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("slice",new Slice()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("replace",new Replace()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("len",new Len()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("del",new Del()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("rename",new Rename()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("find",new Find()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("findall",new FindAll()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("count",new Count()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("quit",new Quit()));
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

//Managecommand::~Managecommand()
//{
//    std::map<std::string, Icommand*>::iterator iter;
//    for(iter = m_mapCommand.begin();iter!=m_mapCommand.end();++iter)
//    {
//        delete iter->second;
//    }
//}

//        if(param.getParam()[0]=="new")
//        {
//            Icommand* command = new New(param);
//            return command;
//        }
//        else if(param.getParam()[0]=="load")
//        {
//            Icommand* command = new Load(param);
//            return command;
//        }
//        else if(param.getParam()[0]=="dup")
//        {
//            Icommand* command = new Dup(param);
//            return command;
//        }
//        else if(param.getParam()[0]=="save")
//        {
//            Icommand* command = new Save(param);
//            return command;
//        }
//        return  NULL;