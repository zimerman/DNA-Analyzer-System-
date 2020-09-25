#include "Terminal.h"
#include "stdlib.h"


void Terminal::start(Iwriter& writer,Ireader& reader,dataDNA &containerDna, CallBack<System>& callBack)
{
    std::string result;

    while (1) {
        writer.setColor("\033[1;34m\033[0m");
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
                writer.setColor("\033[1;32m\033[0m");
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