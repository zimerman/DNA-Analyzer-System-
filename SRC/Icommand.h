//
// Created by a on 7/5/20.
//
#ifndef CODE_ICOMMAND_H
#define CODE_ICOMMAND_H
#include "ParamCommand.h"
#include "DataDNA.h"
#include "DNA.h"
class Icommand {
public:
    Icommand();
    virtual const char* run(const ParamCommand& params)=0;
private:
};
class Icreate: public Icommand
{

};
class New: public Icreate
{
public:
    New(const ParamCommand& params);
    const char* run(const ParamCommand& params);
    static size_t getNumName();
private:
    bool isValid(const ParamCommand& params);
    static size_t m_numName;
};

#endif //CODE_ICOMMAND_H
