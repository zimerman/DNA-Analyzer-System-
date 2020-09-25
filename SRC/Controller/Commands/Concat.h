#ifndef DNA_ANALYZER_PROJECT_CONCAT_H
#define DNA_ANALYZER_PROJECT_CONCAT_H
#include "Icommand.h"


class Concat: public Ichange
{
    public:
        /*virtual*/~Concat(){};
        std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
        std::string  print(Iwriter& writer, dataDNA& containerDna, size_t idDna);
        size_t getIndex(const std::vector<std::string>& param);
        Dnasequence concat(std::vector<size_t> idsDna, size_t lastIndex,dataDNA& containerDna);
        std::string getNewName(std::vector<size_t> idsDna, dataDNA& containerDna,const std::string& paramater);
        std::vector<size_t> getIds(size_t lastIndex, dataDNA& containerDna, std::vector<std::string> param);
};


#endif //DNA_ANALYZER_PROJECT_CONCAT_H
