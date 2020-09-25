#include <fstream>
#include "rawDnaWriter.h"


rawDnaWriter::rawDnaWriter(const std::string& data)
{
    m_data = data;
}


void rawDnaWriter::write(std::string data)const{
    std::ofstream myfile;
    myfile.open(m_data.c_str());
    myfile << data;
    myfile.close();
}
