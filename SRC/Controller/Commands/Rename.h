#ifndef DNA_ANALYZER_PROJECT_RENAME_H
#define DNA_ANALYZER_PROJECT_RENAME_H
#include "Icommand.h"


class Rename:public ImanageDna
{
    public:
        /*virtual*/~Rename(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
    private:
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_RENAME_H
