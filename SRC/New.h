//
// Created by a on 7/8/20.
//

#ifndef SRC_NEW_H
#define SRC_NEW_H

#include "Icommand.h"
#include "ParamCommand.h"
class New: public Icreate
{
    public:
        New(const ParamCommand& params);
        void run(const Iwriter&,const ParamCommand& params,DataDNA& containerDna);
    private:
        bool isValid(const ParamCommand& params);
        void print(const Iwriter& writer,DataDNA& containerDna);
};


#endif //SRC_NEW_H
