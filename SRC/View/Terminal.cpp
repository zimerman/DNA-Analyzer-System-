//
// Created by a on 7/7/20.
//

#include "Terminal.h"
#include "../Controller/Paramcommand.h"
#include "../Controller/Managecommand.h"

#include "stdlib.h"

void Terminal::start(Iwriter& writer,Ireader& reader,dataDNA &containerDna, CallBack<System>& callBack)
{
    std::string result;
    std::cout<<"\033[H\033[J";
    while (1) {
        writer.setColor("\033[1;31m\033[0m");
//        writer.setColor("\033[1m\033[37m");
//        writer.setColor("\033[1m\033[34m");
        writer.write("> cmd >>>");
        reader.read();
        Paramcommand parameter(reader.get());
        try{
            if (parameter.getParam()[0].empty())
            {
                continue;
            }
            result = callBack(writer, reader,containerDna, parameter);
            if (!result.empty())
            {
                if (result == "quit")
                {
                    break;
                }
                writer.write(result);
            }

        }
        catch(std::invalid_argument& e)
        {
            writer.write(e.what());
        }
        catch (const std::exception &e)
        {
            writer.write(e.what());
        }
    }
}