#ifndef DNDSEQUENCE_TERMINAL_H
#define DNDSEQUENCE_TERMINAL_H
#include "UserInterface.h"


class Terminal:public UserInterface
{
    public:
        ~Terminal(){};
        void start(Iwriter& writer, Ireader& reader,dataDNA& containerDna, CallBack<System>& callBack);
};


#endif //DNDSEQUENCE_TERMINAL_H
