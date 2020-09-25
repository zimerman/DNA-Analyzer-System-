#ifndef DNDSEQUENCE_TEXT_H
#define DNDSEQUENCE_TEXT_H
#include "../Controller/Commands/Icommand.h"


class Text: public Filereader
{
    public:
        Text(const char* name_file);
        std::string read()const;
};


#endif //DNDSEQUENCE_TEXT_H
