//
// Created by a on 7/5/20.
//

#include "System.h"
#include "Ireader.h"
#include "Terminal.h"
#include "DataDNA.h"

void System::startApp(Ireader& reader,const Iwriter& writer)
{
    DataDNA dataDna;
    Terminal terminal;
    terminal.start(reader,writer,dataDna);
}
