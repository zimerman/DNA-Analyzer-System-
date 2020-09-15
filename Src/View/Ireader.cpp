//
// Created by a on 6/30/20.
//

#include <fstream>
#include <iostream>
#include "Ireader.h"


std::string Consolereader::get()const
{
    return  m_data;
}

void Consolereader::read()
{
    std::cout<<"> cmd >>>"<<std::endl;
    std::getline(std::cin, m_data,'\n');
}
