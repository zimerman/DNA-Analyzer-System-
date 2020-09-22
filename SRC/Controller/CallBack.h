//
// Created by a on 9/21/20.
//

#ifndef DNA_ANALYZER_PROJECT_CALLBACK_H
#define DNA_ANALYZER_PROJECT_CALLBACK_H

#include <string>
#include "../View/Ireader.h"
#include "../View/Iwriter.h"
#include "../Model/dataDNA.h"
#include "../Controller/Paramcommand.h"

template <typename T>
class CallBack {
public:
    typedef std::string (T::*F)(Iwriter& writer, Ireader& reader, dataDNA& containerDna, Paramcommand& obj);
    CallBack(T instance, F method):m_instance(instance), m_method(method){}
    std::string operator()(Iwriter& writer, Ireader& reader, dataDNA& containerDna, Paramcommand& obj);
private:
    T m_instance;
    F m_method;
};

template <typename T>
std::string CallBack<T>::operator()(Iwriter& writer, Ireader& reader, dataDNA& containerDna, Paramcommand& obj)
{
    return (m_instance.*m_method)(writer, reader, containerDna, obj);
}

#endif //DNA_ANALYZER_PROJECT_CALLBACK_H
