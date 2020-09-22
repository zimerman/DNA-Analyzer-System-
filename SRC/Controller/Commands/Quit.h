//
// Created by a on 9/17/20.
//

#ifndef DNA_ANALYZER_PROJECT_QUIT_H
#define DNA_ANALYZER_PROJECT_QUIT_H


#include "../Paramcommand.h"
#include "Icommand.h"
class Quit:public ControlCommands {
public:
    /*virtual*/~Quit(){}
    /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
private:
    bool isValid(const Paramcommand& param);
    void print(Iwriter& writer, const std::string& string);
};


#endif //DNA_ANALYZER_PROJECT_QUIT_H
