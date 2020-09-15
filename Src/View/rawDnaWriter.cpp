//
// Created by a on 7/7/20.
//

#include <fstream>
#include "rawDnaWriter.h"
#include <string.h>
rawDnaWriter::rawDnaWriter(const std::string& data)
{
    m_data = data;
}


void rawDnaWriter::write(std::string data)const{
    std::ofstream myfile;
//    myfile.open(("../Model/dnaFiles/" + m_data).c_str());
    myfile.open(m_data.c_str());
    myfile << data;
    myfile.close();
}
