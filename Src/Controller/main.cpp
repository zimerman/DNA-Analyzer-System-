//
// Created by a on 7/5/20.
//
#include "System.h"
#include "../View/Iwriter.h"
#include "../View/Ireader.h"
#include "../View/Terminal.h"

int main()
{
    Consolewriter writer;
    Consolereader reader;
    System program;
    Terminal terminal;
    program.start(writer,reader,&terminal);
    return 0;
}
