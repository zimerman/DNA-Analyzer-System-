//
// Created by a on 7/6/20.
//

#ifndef SRC_LOAD_H
#define SRC_LOAD_H

#include "Icommand.h"
#include "ParamCommand.h"
class Load:public Icreate
{
    public:
        Load(const ParamCommand& params);
        const std::string run(const ParamCommand& params);
    private:
        bool isValid(const ParamCommand& params);
        const std::string print();
};


#endif //SRC_LOAD_H
