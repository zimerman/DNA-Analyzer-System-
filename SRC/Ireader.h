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
public:
    FileReader(const char* myfile);
    std::string getData()const;
private:
};




class KeyboardReader:public DataReader
{
public:
    KeyboardReader();
    std::string getData()const;
private:
};

#endif //DNA_IREADER_H
