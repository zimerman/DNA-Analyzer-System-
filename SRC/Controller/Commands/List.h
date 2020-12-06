#ifndef DNA_ANALYZER_PROJECT_LIST_H
#define DNA_ANALYZER_PROJECT_LIST_H
#include "Icommand.h"


class List:public IcontrolCommands
{
    public:
        /*virtual*/~List(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_LIST_H
