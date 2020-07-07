//
// Created by a on 6/30/20.
//

#ifndef DNA_IREADER_H
#define DNA_IREADER_H
#include <fstream>
#include <iostream>

class Ireader {
    public:
        virtual std::string getData()const =0;
    private:
};

class DataReader:public Ireader
{
    protected:
        std::string m_data;
};

class FileReader:public DataReader
{

};

class KeyboardReader:public DataReader
{
    public:
        KeyboardReader();
        std::string getData()const;
};

class FileReaderTxt: public FileReader
{
    public:
        FileReaderTxt(const char* myfile);
        std::string getData()const;
};

class FileReaderRwadna: public FileReader
{
public:
    FileReaderRwadna(const char* myfile);
    std::string getData()const;
};

#endif //DNA_IREADER_H
