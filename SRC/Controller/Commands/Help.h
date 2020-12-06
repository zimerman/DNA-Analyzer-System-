#ifndef DNA_ANALYZER_PROJECT_HELP_H
#define DNA_ANALYZER_PROJECT_HELP_H
#include "Icommand.h"


class Help:public IcontrolCommands
{
    public:
        /*virtual*/~Help(){}
        /*virtual*/std::string run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param);
        static void initializeMapAbout();

    private:
        static std::map<std::string, std::string> m_mapAbout;
        bool isValid(const Paramcommand& param);
};


#endif //DNA_ANALYZER_PROJECT_HELP_H
