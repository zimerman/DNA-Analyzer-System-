//
// Created by a on 7/5/20.
//
#include "System.h"
#include "../View/Iwriter.h"
#include "../View/Ireader.h"
#include "../View/Terminal.h"
#include <stdlib.h>

int main()
{
    std::cout << "\033[1;31mbold red text\033[0m\n";
    Consolewriter writer;
    Consolereader reader;
    System program;
    Terminal terminal;
    program.start(writer,reader,terminal);
    return 0;
}
