//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_PROJECT_LEN_H
#define DNA_ANALYZER_PROJECT_LEN_H

#include "../ImanageDna.h"
#include "../../View/rawDnaWriter.h"

class Len: public ImanageDna{

public:
    /*virtual*/~Len(){}
    /*virtual*/void run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param);

private:
    bool isValid(const Paramcommand& param);
    void print(const Iwriter& writer, size_t len);
};


#endif //DNA_ANALYZER_PROJECT_LEN_H
