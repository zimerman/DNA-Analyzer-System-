//
// Created by a on 9/14/20.
//

#ifndef DNA_ANALYZER_PROJECT_USERINTERFACE_H
#define DNA_ANALYZER_PROJECT_USERINTERFACE_H

#include "../Model/dataDNA.h"
#include "../Controller/System.h"
#include "../Controller/CallBack.h"
class UserInterface {
public:
    virtual ~UserInterface(){};
    virtual void start(Iwriter& writer, Ireader& reader,dataDNA& containerDna, CallBack<System>& callBack)=0;
};


#endif //DNA_ANALYZER_PROJECT_USERINTERFACE_H
