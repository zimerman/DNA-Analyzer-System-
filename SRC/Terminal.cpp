//
// Created by a on 7/7/20.
//

#include "Terminal.h"
#include "Icommand.h"
#include "ManageCommand.h"
#include "DataDNA.h"

void Terminal::start(Ireader& reader,const Iwriter& writer,DataDNA& dataDna)
{
    int flag=1;
    while(flag)
    {
        reader.read();
        ParamCommand paramCommand(reader.getData());
        try{
            Icommand* icommand = ManageCommand::createCtorCommand(paramCommand);
            icommand->run(writer,paramCommand,dataDna);
        }
        catch(std::invalid_argument& e)
        {
            std::cout<<e.what();
        }

    }
}
