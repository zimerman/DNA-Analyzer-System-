//
// Created by a on 6/30/20.
//

#include "Ireader.h"

std::string KeyboardReader::getData()const
{
    return m_data;
}

FileReaderTxt::FileReaderTxt(const std::string& myfile)
{
    m_name_file = myfile;
}

std::string FileReaderTxt::getData()const
{
    return m_data;
}

FileReaderRwadna::FileReaderRwadna(const std::string& myfile)
{
    m_name_file = myfile;
}

std::string FileReaderRwadna::getData()const
{
    return m_data;
}

void FileReaderRwadna::read()
{
    std::ifstream data_file(m_name_file.c_str());
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

void KeyboardReader::read()
{
    std::cout<<"> cmd >>> ";
    std::getline(std::cin, m_data);
}