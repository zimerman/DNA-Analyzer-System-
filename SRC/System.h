//
// Created by a on 7/5/20.
//

#ifndef SRC_SYSTEM_H
#define SRC_SYSTEM_H

#include "Ireader.h"
#include "Iwriter.h"

class System {
    public:
        void startApp(Ireader& reader,const Iwriter& writer);
};


#endif //SRC_SYSTEM_H
