//
// Created by a on 7/5/20.
//

#include "System.h"
#include "../View/Iwriter.h"
#include "../View/Ireader.h"
#include "../Model/dataDNA.h"
#include "../View/Terminal.h"
#include "stdlib.h"
void System::start(const Iwriter& writer, Ireader& reader,UserInterface* UI)
{
    dataDNA containerDna;
    int t = UI->start(writer,reader,containerDna);
    if(t==-1)
    {
        exit(0);
    }
}

