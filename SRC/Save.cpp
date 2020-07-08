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
    return (params.getParam().size() == 2 || ((params.getParam().size() == 3) && (params.getParam()[2][0] == '@')))&&(params.getParam()[1][0]=='#');
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
    if(!containerDna.isExistId(id))
    {
        std::cout<<"this key not found in map";
        return;
    }
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