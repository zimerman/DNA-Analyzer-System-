#ifndef DNA_ANALYZER_PROJECT_LEN_H
#define DNA_ANALYZER_PROJECT_LEN_H
#include "Icommand.h"


class Len: public ImanageDna
{
    public:
        /*virtual*/~Len(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_LEN_H
