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
        virtual void read()=0;
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
        std::string getData()const;
        void read();
    private:
        std::string m_name_file;
};

class FileReaderTxt: public FileReader
{
    public:
        FileReaderTxt(const std::string& myfile);
        std::string getData()const;
    private:
        std::string m_name_file;

};

class FileReaderRwadna: public FileReader
{
public:
    FileReaderRwadna(const std::string& myfile);
    std::string getData()const;
    void read();
private:
    std::string m_name_file;
};

#endif //DNA_IREADER_H
