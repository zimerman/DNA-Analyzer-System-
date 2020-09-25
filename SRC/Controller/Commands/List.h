#ifndef DNA_ANALYZER_PROJECT_LIST_H
#define DNA_ANALYZER_PROJECT_LIST_H
#include "../Paramcommand.h"
#include "Icommand.h"
#include "../ImanageDna.h"


class List:public ControlCommands
{
    public:
        /*virtual*/~List(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_LIST_H
