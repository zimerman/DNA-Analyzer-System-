//
// Created by a on 7/5/20.
//
#ifndef CODE_ICOMMAND_H
#define CODE_ICOMMAND_H
#include "ParamCommand.h"
#include "DataDNA.h"
#include "DNA.h"
class Icommand
{
    public:
        Icommand(){};
        virtual void run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)=0;
};

class Icreate: public Icommand
{

};



#endif //CODE_ICOMMAND_H
