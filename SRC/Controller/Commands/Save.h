#ifndef DNDSEQUENCE_SAVE_H
#define DNDSEQUENCE_SAVE_H
#include "Icommand.h"
#include "../../View/rawDnaWriter.h"


class Save: public ImanageDna
{
    public:
        /*virtual*/~Save(){}
        std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& obj);

    private:
        bool isValid(const Paramcommand& obj);
        std::string save(dataDNA& containerDna,const Paramcommand&param, size_t idDna);
};


#endif //DNDSEQUENCE_SAVE_H
