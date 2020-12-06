#ifndef DNA_ANALYZER_PROJECT_COUNT_H
#define DNA_ANALYZER_PROJECT_COUNT_H
#include "Icommand.h"


class Count:public IsequenceAnalysis
{
    public:
        /*virtual*/~Count(){};
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
    private:
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_COUNT_H
