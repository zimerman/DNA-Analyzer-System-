#ifndef DNA_ANALYZER_PROJECT_DEL_H
#define DNA_ANALYZER_PROJECT_DEL_H
#include "Icommand.h"
#include "../../View/rawDnaWriter.h"

class Del: public ImanageDna
{
    public:
        /*virtual*/~Del(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
    private:
        bool isValid(const Paramcommand& param);
        std::string print(Iwriter& writer, dataDNA& containerDna, size_t idDna);
        std::string deleteDna(dataDNA& containerDna,size_t idDna,Ireader& reader,Iwriter& writer);
};


#endif //DNA_ANALYZER_PROJECT_DEL_H
