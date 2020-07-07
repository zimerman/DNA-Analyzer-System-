//
// Created by a on 6/30/20.
//

#include "Ireader.h"

KeyboardReader::KeyboardReader()
{
    std::cout<<"> cmd >>> ";
    std::getline(std::cin, m_data);
}

std::string KeyboardReader::getData()const
{
    return m_data;
}

FileReaderTxt::FileReaderTxt(const char* myfile)
{
    std::ifstream data_file(myfile);
    std::string line;
    if (data_file.is_open())
    {
        std::getline(data_file,line);
    }
    else
    {
        throw std::ios_base::failure("this file not exist");
    }
    data_file.close();
    m_data = line;
}

std::string FileReaderTxt::getData()const
{
    return m_data;
}

FileReaderRwadna::FileReaderRwadna(const char* myfile)
{
    std::ifstream data_file(myfile);
    std::string line;
    if (data_file.is_open())
    {
        std::getline(data_file,line);
    }
    else
    {
        throw std::ios_base::failure("this file not exist");
    }
    data_file.close();
    m_data = line;
}

std::string FileReaderRwadna::getData()const
{
    return m_data;
}

