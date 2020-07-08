//
// Created by a on 7/7/20.
//

#ifndef SRC_DUP_H
#define SRC_DUP_H


#include "Ireader.h"
#include "Icommand.h"
#include "ParamCommand.h"

class Dup: public Icreate {
public:
    Dup(const ParamCommand& params);
    void run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna);
private:
    bool isValid(const ParamCommand& params);
    void print(const Iwriter& writer,DataDNA& containerDna);
};




#endif //SRC_DUP_H
