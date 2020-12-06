#ifndef DNA_ANALYZER_PROJECT_FIND_H
#define DNA_ANALYZER_PROJECT_FIND_H
#include "Icommand.h"


class Find:public IsequenceAnalysis
{
    public:
        /*virtual*/~Find(){};
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_FIND_H
