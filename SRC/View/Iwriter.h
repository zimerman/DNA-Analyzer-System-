#ifndef DNA_IWRITER_H
#define DNA_IWRITER_H
#include <iostream>


class Iwriter
{
    public:
        virtual void write(std::string data)const=0;
        virtual void setColor(std::string color)=0;
};


class Datawriter:public Iwriter
{
    protected:
        std::string m_data;
};


class Filewriter:public Datawriter{

};


class Consolewriter:public Datawriter
{
    public:
        void write(std::string data)const;
        void setColor(std::string color);

    private:
        std::string m_color;

};


#endif //DNA_IWRITER_H
