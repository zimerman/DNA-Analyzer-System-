#ifndef DNA_ANALYZER_PROJECT_QUIT_H
#define DNA_ANALYZER_PROJECT_QUIT_H
#include "Icommand.h"


class Quit:public IcontrolCommands
{
    public:
        /*virtual*/~Quit(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);

    private:
        bool isValid(const Paramcommand& param);
        void print(Iwriter& writer, const std::string& string);
};


#endif //DNA_ANALYZER_PROJECT_QUIT_H
