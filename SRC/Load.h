//
// Created by a on 7/6/20.
//

#ifndef SRC_LOAD_H
#define SRC_LOAD_H

#include "Icommand.h"
#include "ParamCommand.h"
class Load:public Icreate
{
    public:
        Load(const ParamCommand& params);
        void run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna);
    private:
        bool isValid(const ParamCommand& params);
        void print(const Iwriter& writer,DataDNA& containerDna);
};

#endif //SRC_LOAD_H
