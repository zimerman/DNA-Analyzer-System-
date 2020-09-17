//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_PROJECT_REENUM_H
#define DNA_ANALYZER_PROJECT_REENUM_H

#include "../ImanageDna.h"

class ReEnum:public ImanageDna{

public:
    /*virtual*/~ReEnum(){}
    /*virtual*/void run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& param);
private:
    bool isValid(const Paramcommand& param);
    //void print(const Iwriter& writer, dataDNA& containerDna);
};


#endif //DNA_ANALYZER_PROJECT_REENUM_H
