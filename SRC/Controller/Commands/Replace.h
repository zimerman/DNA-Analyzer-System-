#ifndef DNA_ANALYZER_PROJECT_REPLACE_H
#define DNA_ANALYZER_PROJECT_REPLACE_H
#include "Icommand.h"


class Replace: public Ichange
{
    public:
        /*virtual*/~Replace(){};
        std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
        std::string  print(Iwriter& writer, dataDNA& containerDna, size_t idDna);
        size_t getIndex(const std::vector<std::string>& param);
        Dnasequence replace(const std::vector<std::string>& param, size_t lastIndex,dataDNA& containerDna,size_t idDna);
};


#endif //DNA_ANALYZER_PROJECT_REPLACE_H
