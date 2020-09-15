//
// Created by a on 7/5/20.
//

#ifndef DNDSEQUENCE_ICOMMAND_H
#define DNDSEQUENCE_ICOMMAND_H

#include "../Paramcommand.h"
#include "../../Model/dataDNA.h"
#include <string>

class Icommand{

public:
    virtual ~Icommand(){};
    virtual void run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& obj) = 0;

};

class Icreate:public Icommand{
public:
    virtual ~Icreate(){};
};


class Ichange:public Icommand{
public:
    virtual ~Ichange(){};
};



#endif //DNDSEQUENCE_ICOMMAND_H
