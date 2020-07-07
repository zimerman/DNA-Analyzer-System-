//
// Created by a on 6/30/20.
//

#include <iostream>
#include "Iwriter.h"

void FileWriter::write(const std::string& data)const
{
    std::ofstream myfile1;
    myfile1.open (m_naneWriter.c_str());
    myfile1 << data;
    myfile1.close();
}

void KeyBoardWriter::write(const std::string& data)const
{
    std::cout<<data;
}

FileWriter::FileWriter(std::string name)
{
    m_naneWriter=name;
}
