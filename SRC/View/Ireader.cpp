#include <iostream>
#include "Ireader.h"


std::string Consolereader::get()const
{
    return  m_data;
}


void Consolereader::read()
{
    std::getline(std::cin, m_data,'\n');
}


void Consolereader::setColor(std::string color)
{
    m_color = color;
}
