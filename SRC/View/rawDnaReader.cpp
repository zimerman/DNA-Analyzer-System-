#include <string>
#include "rawDnaReader.h"


rawDnaReader::rawDnaReader(const std::string& name_file){
     m_nameFile = name_file;
}


void rawDnaReader::read()
{
    std::ifstream myfile(m_nameFile.c_str());

    if(myfile.is_open())
    {
        std::getline(myfile,m_data);
    }
    else
    {
        throw std::ios_base::failure("faild open file");
    }

    myfile.close();
}


std::string rawDnaReader::get()const
{
    return m_data;
}
