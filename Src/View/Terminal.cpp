//
// Created by a on 7/7/20.
//

#include "Terminal.h"
#include "../Controller/Paramcommand.h"
#include "../Controller/Managecommand.h"
#include "stdlib.h"
int Terminal::start(const Iwriter& writer,Ireader& reader,dataDNA &containerDna)
{
    Managecommand manageCommand;
    while (1) {
        reader.read();
        Paramcommand parameter(reader.get());
        try{
            Icommand *command = manageCommand.createcommand(parameter.getParam()[0]);
            if(command==NULL)
            {
                return -1;
            }
            command->run(writer,containerDna, parameter);
        }
        catch(std::invalid_argument& e)
        {
            std::cout<<e.what()<<std::endl;
        }

    }

}