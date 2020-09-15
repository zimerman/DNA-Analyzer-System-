//
// Created by a on 7/6/20.
//

#ifndef DNDSEQUENCE_RAWDNAREADER_H
#define DNDSEQUENCE_RAWDNAREADER_H

#include "../Controller/Commands/Icommand.h"

class rawDnaReader: public Filereader {

public:

    rawDnaReader(const std::string& name_file);
    void read();
    std::string get()const;
};


#endif //DNDSEQUENCE_RAWDNAREADER_H
