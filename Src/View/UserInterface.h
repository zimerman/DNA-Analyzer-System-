//
// Created by a on 9/14/20.
//

#ifndef DNA_ANALYZER_PROJECT_USERINTERFACE_H
#define DNA_ANALYZER_PROJECT_USERINTERFACE_H

#include "../Model/dataDNA.h"

class UserInterface {
public:
//    ~UserInterface();
    virtual int start(const Iwriter& writer, Ireader& reader,dataDNA& containerDna)=0;
};


#endif //DNA_ANALYZER_PROJECT_USERINTERFACE_H
