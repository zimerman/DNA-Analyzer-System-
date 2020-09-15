//
// Created by a on 7/6/20.
//

#include <fstream>
#include "Text.h"
////////files/////////

Text::Text(const char* name_file){
    std::ifstream myfile(name_file);
    if(myfile.is_open())
    {
        getline(myfile,m_data);
    }
    else{
        throw std::ios_base::failure("faild open file");
    }
    myfile.close();
}

std::string Text::read()const
{
    return m_data;

}

