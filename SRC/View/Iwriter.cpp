#include "Iwriter.h"
#include <iostream>


void Consolewriter::write(std::string data)const
{
    std::cout<<m_color.substr(0,7)+data+m_color.substr(11)<<std::endl;
}


void Consolewriter::setColor(std::string color)
{
    m_color = color;
}