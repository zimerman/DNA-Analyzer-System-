//
// Created by a on 6/30/20.
//

#ifndef DNA_IWRITER_H
#define DNA_IWRITER_H
#include <fstream>

class Iwriter
{
    public:
        virtual void write(const std::string& data)const =0;
};

class NameWriter:public Iwriter
{
    protected:
        std::string m_naneWriter;
};

class FileWriter:public NameWriter
{
    public:
        FileWriter(std::string name);
        void write(const std::string& data)const ;
};

class KeyBoardWriter:public NameWriter
{
    public:
        void write(const std::string& data)const ;
};


#endif //DNA_IWRITER_H
