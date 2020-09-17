//
// Created by a on 7/6/20.
//

#ifndef DNDSEQUENCE_LOAD_H
#define DNDSEQUENCE_LOAD_H


#include "../Paramcommand.h"
#include "Icommand.h"
class Load:public Icreate {

public:

//    Load(const Paramcommand& param);
    /*virtual*/~Load(){}
    void run(const Iwriter& writer, Ireader& reader,dataDNA& containerDna,const Paramcommand& obj);

private:

    bool isValid(const Paramcommand& obj);
    void print(const Iwriter& writer, dataDNA& containerDna)const;

};


#endif //DNDSEQUENCE_LOAD_H
