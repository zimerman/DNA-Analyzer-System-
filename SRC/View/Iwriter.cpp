//
// Created by a on 6/30/20.
//

#include "Iwriter.h"
#include <iostream>
#include <fstream>


void Consolewriter::write(std::string data)const
{
    std::cout<<m_color.substr(0,7)+data+m_color.substr(11)<<std::endl;
//    std::cout<<m_color.substr(0,4)+data+m_color.substr(9)<<std::endl;
}

void Consolewriter::setColor(std::string color)
{
    m_color = color;
}