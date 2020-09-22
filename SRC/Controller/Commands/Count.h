//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_PROJECT_COUNT_H
#define DNA_ANALYZER_PROJECT_COUNT_H

#include "Icommand.h"

class Count:public SequenceAnalysis {
public:
    /*virtual*/~Count(){};
    /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
private:
    bool isValid(const Paramcommand& param);
//    void print(const Iwriter& writer, const std::string& string);
};


#endif //DNA_ANALYZER_PROJECT_COUNT_H
