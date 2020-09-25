#ifndef DNA_IREADER_H
#define DNA_IREADER_H
#include "string"


class Ireader
{
    public:
        virtual void read()=0 ;
        virtual std::string get()const =0 ;
        virtual void setColor(std::string color)=0;
};


class Datareader:public Ireader
{
    protected:
         std::string m_data;
         std::string m_nameFile;
};


class Filereader:public Datareader{

};

class Consolereader:public Datareader
{
    public:
        std::string get()const;
        void read();
        void setColor(std::string color);

    private:
        std::string m_color;
};


#endif //DNA_IREADER_H
