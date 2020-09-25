#ifndef DNDSEQUENCE_DUP_H
#define DNDSEQUENCE_DUP_H
#include "Icommand.h"


class Dup:public Icommand
{
    public:
        /*virtual*/~Dup(){}
        std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& obj);

    private:
        bool isValid(const Paramcommand& obj);
        std::string print(Iwriter& writer, dataDNA& containerDna);
        Dna* dup(dataDNA&containerDna, const Paramcommand&param, size_t idDna);
};


#endif //DNDSEQUENCE_DUP_H
