//
// Created by a on 9/15/20.
//

#ifndef DNA_ANALYZER_PROJECT_REPLACE_H
#define DNA_ANALYZER_PROJECT_REPLACE_H

#include "Icommand.h"

class Replace: public Ichange {
public:
    /*virtual*/~Replace(){};
    void run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& param);
private:
    bool isValid(const Paramcommand& param);
    void print(const Iwriter& writer, dataDNA& containerDna, size_t idDna);
    size_t getIndex(const std::vector<std::string>& param);
    Dnasequence replace(const std::vector<std::string>& param, size_t lastIndex,dataDNA& containerDna,size_t idDna);
};


#endif //DNA_ANALYZER_PROJECT_REPLACE_H