//
// Created by a on 7/7/20.
//

#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H

#include "Ireader.h"
#include "Iwriter.h"
#include "DataDNA.h"

class Terminal {
public:
    void start(Ireader& reader,const Iwriter& writer,DataDNA& dataDna);
};


#endif //SRC_TERMINAL_H
