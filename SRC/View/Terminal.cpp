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
        std::cout<<"> cmd >>>"<<std::endl;
        reader.read();
        Paramcommand parameter(reader.get());
        try{
            Icommand *command = manageCommand.createcommand(parameter.getParam()[0]);
            if(command==NULL)
            {
                continue;
            }
            command->run(writer, reader, containerDna, parameter);

        }
        catch(std::invalid_argument& e)
        {
            std::cout<<e.what()<<std::endl;
        }
        catch (const std::exception &e)
        {
            return -1;
        }
    }
}