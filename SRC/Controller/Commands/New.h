//
// Created by a on 9/14/20.
//

#ifndef DNA_ANALYZER_PROJECT_NEW_H
#define DNA_ANALYZER_PROJECT_NEW_H
#include "../ImanageDna.h"
#include "../../View/rawDnaWriter.h"
class New:public Icreate{

public:
//    New(const Paramcommand& obj);
    /*virtual*/~New(){};
    void run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& obj);

private:
    bool isValid(const Paramcommand& obj);
    void print(const Iwriter& writer, dataDNA& containerDna);

};

#endif //DNA_ANALYZER_PROJECT_NEW_H
