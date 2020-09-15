//
// Created by a on 6/30/20.
//

#ifndef DNA_IWRITER_H
#define DNA_IWRITER_H

#include <iostream>

class Iwriter{

public:
  virtual void write(std::string data)const=0;

};


class Datawriter:public Iwriter{

protected:
    std::string m_data;

};


class Filewriter:public Datawriter{

};


class Consolewriter:public Datawriter{

public:
    void write(std::string data)const;


};


#endif //DNA_IWRITER_H
