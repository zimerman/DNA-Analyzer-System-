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
    virtual void run(const Iwriter& writer,Ireader& reader, dataDNA& containerDna,const Paramcommand& obj) = 0;

};

class Icreate:public Icommand{
public:
    virtual ~Icreate(){};
};


class Ichange:public Icommand{
public:
    virtual ~Ichange(){};
protected:
    std::string getName(size_t idDna, const std::string& suffix, dataDNA& containerDna, const std::string& paramater);
};


class SequenceAnalysis:public Icommand {
public:
    virtual ~SequenceAnalysis(){};
};


class ControlCommands:public Icommand{
public:
    virtual ~ControlCommands(){};
};

#endif //DNDSEQUENCE_ICOMMAND_H
