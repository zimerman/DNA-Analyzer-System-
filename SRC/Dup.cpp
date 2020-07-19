//
// Created by a on 7/7/20.
//

#include <sstream>
#include "Dup.h"
#include "AuxiliaryFunctions.h"
bool Dup::isValid(const ParamCommand& params)
{
    return true;//(params.getParam().size() == 2 || ((params.getParam().size() == 3) && (params.getParam()[2][0] == '@'))) && (params.getParam()[1][0] == '#');
}

Dup::Dup(const ParamCommand& params)
{
    if(!isValid(params))
    {
        throw std::invalid_argument("this command is not valid to Load");
    }
}

void Dup::run(const Iwriter& writer,const ParamCommand& params,DataDNA& containerDna)
{
    static size_t count=1;
    std::string nameDna;
    DNA* obj1;
    if(params.getParam()[1][0] == '#')
    {
        size_t id = castToSizet(((params.getParam())[1]).substr(1));
        if(!(containerDna.isExistId(id)))
        {
            std::cout<<"this key not found in map";
            return;
        }
        if(params.getParam().size()<3)
        {
            /*std::string result = castToString(count);
            nameDna = containerDna.find(id)->getName() + "_" + result;
            count++;*/
            std::string result = castToString(count);
            while(containerDna.isExistId(count))
            {
                nameDna = containerDna.find(id)->getName() + "_" + result;
                count++;
                result = castToString(count);
            }
        }
        else
        {
            nameDna = (params.getParam())[2];
        }
        obj1 = new DNA(nameDna,"new",containerDna.find(id)->getDnaSeq());
    }
    else
    {
        std::string name = ((params.getParam())[1]).substr(1);
        //size_t id = castToSizet(((params.getParam())[1]).substr(1));
        /*if(containerDna.isExist(name))
        {
            std::cout<<"this key name not found in map";
            return;
        }*/
        if(params.getParam().size()<3)
        {
            /*std::string result = castToString(count);
            nameDna = containerDna.find(id)->getName() + "_" + result;
            count++;*/
            std::string result = castToString(count);
            while(containerDna.isExistId(count))
            {
                nameDna = containerDna.getNameDna(name)->getName()+"_"+result;
                count++;
                result = castToString(count);
            }
        }
        else
        {
            std::cout<<"\n123\n";
            nameDna = (params.getParam())[2];
        }
        std::cout<<"\n123\n";
        obj1 = new DNA(nameDna,"new",containerDna.getNameDna(name)->getDnaSeq());
        //obj1 = new DNA(nameDna,"new",containerDna.find(id)->getDnaSeq());
    }
    std::cout<<"\n123\n";
    containerDna.addDataDNAidtodna(obj1);
    containerDna.addDataDNAnametoid(nameDna);
    print(writer, containerDna);
}

void Dup::print(const Iwriter& writer,DataDNA& containerDna)
{
    std::string result2;
    std::stringstream sstm2;
    sstm2 << containerDna.getDataDNAidtodna()[DNA::getId()]->getId();
    result2 = sstm2.str();
    writer.write("\n["+result2+"] " +containerDna.find(DNA::getId())->getName() + ": "+containerDna.getDataDNAidtodna()[DNA::getId()]->getDnaSeq()+"\n");
}
