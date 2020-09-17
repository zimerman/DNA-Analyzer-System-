//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_PROJECT_DEL_H
#define DNA_ANALYZER_PROJECT_DEL_H

#include "../ImanageDna.h"
#include "../../View/rawDnaWriter.h"

class Del: public ImanageDna{

public:
    /*virtual*/~Del(){}
    /*virtual*/void run(const Iwriter& writer,Ireader& reader, dataDNA& containerDna,const Paramcommand& param);
private:
    bool isValid(const Paramcommand& param);
    void print(const Iwriter& writer, dataDNA& containerDna, size_t idDna);
    void deleteDna(dataDNA& containerDna,size_t idDna,Ireader& reader,const Iwriter& writer);
};


#endif //DNA_ANALYZER_PROJECT_DEL_H
