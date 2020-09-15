//
// Created by a on 7/7/20.
//

#ifndef DNDSEQUENCE_RAWDNAWRITER_H
#define DNDSEQUENCE_RAWDNAWRITER_H

#include "Iwriter.h"

class rawDnaWriter: public Filewriter{

public:
    rawDnaWriter(const std::string& data);
    void write(std::string data)const;

};


#endif //DNDSEQUENCE_RAWDNAWRITER_H
