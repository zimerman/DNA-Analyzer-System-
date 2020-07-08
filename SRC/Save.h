//
// Created by a on 7/7/20.
//

#ifndef SRC_SAVE_H
#define SRC_SAVE_H


#include "IManageaDna.h"

class Save: public IManageaDna
{
    public:
        Save(const ParamCommand& params);
        void run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna);
    private:
        bool isValid(const ParamCommand& params);
        const std::string print();
};


#endif //SRC_SAVE_H