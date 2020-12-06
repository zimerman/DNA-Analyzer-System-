#ifndef DNDSEQUENCE_ICOMMAND_H
#define DNDSEQUENCE_ICOMMAND_H
#include "../Paramcommand.h"
#include "../../Model/dataDNA.h"
#include <string>


class Icommand
{
    public:
        virtual ~Icommand(){};
        virtual std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& obj) = 0;
        size_t getId(dataDNA& containerDna, std::string& dna);
};


class Icreate:public Icommand
{
    public:
        virtual ~Icreate(){};
};


class Ichange:public Icommand
{
    public:
        virtual ~Ichange(){};

    protected:
        std::string getName(size_t idDna, const std::string& suffix, dataDNA& containerDna, const std::string& paramater);
};


class IsequenceAnalysis: public Icommand
{
    public:
        virtual ~IsequenceAnalysis(){};
};


class IcontrolCommands: public Icommand
{
    public:
        virtual ~IcontrolCommands(){};
};


class ImanageDna: public Icommand
{
public:
    virtual ~ImanageDna(){}
};


#endif //DNDSEQUENCE_ICOMMAND_H
