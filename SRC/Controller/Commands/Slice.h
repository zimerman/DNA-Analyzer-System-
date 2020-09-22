//
// Created by a on 9/14/20.
//

#ifndef DNA_ANALYZER_PROJECT_SLICE_H
#define DNA_ANALYZER_PROJECT_SLICE_H

#include "Icommand.h"

class Slice: public Ichange {
public:
    /*virtual*/~Slice(){};
    std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
private:
    bool isValid(const Paramcommand& obj);
    std::string print(Iwriter& writer, dataDNA& containerDna, size_t idDna);
};


#endif //DNA_ANALYZER_PROJECT_SLICE_H
