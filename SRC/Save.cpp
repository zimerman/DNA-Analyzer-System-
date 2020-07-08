//
// Created by a on 7/7/20.
//

//
// Created by a on 7/7/20.
//

#include <sstream>
#include "Save.h"
bool Save::isValid(const ParamCommand& params)
{
    return true;
}

Save::Save(const ParamCommand& params)
{
    if(!isValid(params))
    {
        throw std::invalid_argument("error in Load");
    }
}
void Save::run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)
{
    std::string name = ((params.getParam())[1]);
    std::stringstream temp(name);
    size_t id;
    temp >> id;
    if(params.getParam().size()<3)
    {
        FileWriter myfile(containerDna.find(id)->getName());
        myfile.write(containerDna.find(id)->getDnaSeq());
    }
    else
    {
        FileWriter myfile(params.getParam()[2]);
        myfile.write(containerDna.find(id)->getDnaSeq());
    }
}