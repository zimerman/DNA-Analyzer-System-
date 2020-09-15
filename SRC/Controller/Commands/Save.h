//
// Created by a on 7/6/20.
//

#ifndef DNDSEQUENCE_SAVE_H
#define DNDSEQUENCE_SAVE_H

#include "../ImanageDna.h"
#include "../../View/rawDnaWriter.h"

class Save: public ImanageDna{

public:
    /*virtual*/~Save(){}
//    Save(const Paramcommand& obj);
    void run(const Iwriter& writer, dataDNA& containerDna,const Paramcommand& obj);

private:
    bool isValid(const Paramcommand& obj);
    //void print(const Iwriter& writer, dataDNA& containerDna);
    std::string saveById(dataDNA& containerDna,const Paramcommand&param);
    std::string saveByName(dataDNA& containerDna, const Paramcommand&param);


};


#endif //DNDSEQUENCE_SAVE_H
