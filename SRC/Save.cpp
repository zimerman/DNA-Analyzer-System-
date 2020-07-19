//
// Created by a on 7/7/20.
//


#include <sstream>
#include "Save.h"
bool Save::isValid(const ParamCommand& params)
{
    return (params.getParam().size() == 2 || ((params.getParam().size() == 3) && (params.getParam()[2][0] == '@'))) && (params.getParam()[1][0] == '#' || params.getParam()[1][0] == '@');
}

Save::Save(const ParamCommand& params)
{
    if(!isValid(params))
    {
        throw std::invalid_argument("\"this command is not valid to save\n");
    }
}

void Save::run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)
{
    if(params.getParam()[1][0] == '#') {
        std::string name = ((params.getParam())[1].substr(1));
        std::stringstream temp(name);
        size_t id;
        temp >> id;
        std::string nameFile;
        if (!(containerDna.isExistId(id))) {
            std::cout << "this key id not found in map";
            return;
        }
        if (params.getParam().size() < 3) {
            nameFile = containerDna.find(id)->getName()+".rawdna";
        } else {
            nameFile = params.getParam()[2].substr(1);
        }
        containerDna.find(id)->getStatus().setStatus("up to date");
        FileWriter myfile(nameFile);
        myfile.write(containerDna.find(id)->getDnaSeq());
        //std::cout<<containerDna.find(id)->getStatus().getStatus();
    }
    else
    {
        std::string name = ((params.getParam())[1].substr(1));
        std::string nameFile;
        std::cout<<"@@@@@"<<name;
        if (!(containerDna.isExist(name))) {
            std::cout << "this key name not found in map";
            return;
        }
        if (params.getParam().size() < 3) {
            nameFile = containerDna.getNameDna(name)->getName()+".rawdna";

        } else {
            nameFile = params.getParam()[2].substr(1);

        }
        containerDna.getNameDna(name)->getStatus().setStatus("up to date");
        FileWriter myfile(nameFile);
        myfile.write(containerDna.getNameDna(name)->getDnaSeq());
    }
}
//save