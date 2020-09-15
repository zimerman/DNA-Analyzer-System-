//
// Created by a on 7/5/20.
//

#include "Managecommand.h"
#include <stdlib.h>
//#include <string.h>

Managecommand::Managecommand()
{
    m_mapCommand.insert(std::pair<std::string, Icommand*>("new",new New()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("load",new Load()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("dup",new Dup()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("save",new Save()));
    m_mapCommand.insert(std::pair<std::string, Icommand*>("slice",new Slice()));
}

Icommand* Managecommand::createcommand(const std::string& command)
{
    if(command=="quit")
    {
        return NULL;
    }
    std::map<std::string, Icommand*>::iterator indexCommand = m_mapCommand.find(command);
    if(indexCommand!=m_mapCommand.end())
    {
        return indexCommand->second;
    }
    return NULL;
}

Managecommand::~Managecommand()
{
    std::map<std::string, Icommand*>::iterator iter;
    for(iter = m_mapCommand.begin();iter!=m_mapCommand.end();++iter)
    {
        delete iter->second;
    }
}

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