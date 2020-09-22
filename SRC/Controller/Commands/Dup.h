//
// Created by a on 7/7/20.
//

#ifndef DNDSEQUENCE_DUP_H
#define DNDSEQUENCE_DUP_H

#include "Icommand.h"

class Dup:public Icommand {
public:
//    Dup(const Paramcommand& obj);
    /*virtual*/~Dup(){}
    std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& obj);

private:
    bool isValid(const Paramcommand& obj);
    std::string print(Iwriter& writer, dataDNA& containerDna);
    Dna* dupByName(dataDNA&containerDna, const Paramcommand&param);
    Dna* dupById(dataDNA&containerDna, const Paramcommand&param);
};


#endif //DNDSEQUENCE_DUP_H
