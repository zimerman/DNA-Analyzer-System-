//
// Created by a on 9/14/20.
//

#ifndef DNA_ANALYZER_PROJECT_SLICE_H
#define DNA_ANALYZER_PROJECT_SLICE_H

#include "Icommand.h"

class Slice: public Ichange {
public:
    /*virtual*/~Slice(){};
    void run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& param);
private:
    bool isValid(const Paramcommand& obj);
    void print(const Iwriter& writer, dataDNA& containerDna, size_t idDna);
};


#endif //DNA_ANALYZER_PROJECT_SLICE_H
