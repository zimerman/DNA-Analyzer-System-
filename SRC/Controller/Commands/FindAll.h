//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_PROJECT_FINDALL_H
#define DNA_ANALYZER_PROJECT_FINDALL_H

#include "Icommand.h"

class FindAll:public SequenceAnalysis {
public:
    /*virtual*/~FindAll(){};
    /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
private:
    bool isValid(const Paramcommand& param);
    std::string print(Iwriter& writer, std::list<size_t>& listStrin);
};


#endif //DNA_ANALYZER_PROJECT_FINDALL_H
