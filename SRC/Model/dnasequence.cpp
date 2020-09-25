#include "dnasequence.h"
#include <cstring>
#include "string"
#include "vector"


bool Dnasequence::isValid(const char* str)
{
    if(!str)
        throw std::invalid_argument("cstring is not valide");
    if(!(strspn(str,"ACTG")==strlen(str)))
        throw std::invalid_argument( "invalid DNA" );
    return true;
}


Dnasequence::Dnasequence(const std::string& cString)
{
    if(isValid(cString.c_str()))
    {
        m_lenCstringDna = cString.length();
        this->init(cString.c_str());
    }

}


Dnasequence::Dnasequence(const Dnasequence& obj)
{
    m_lenCstringDna=obj.m_lenCstringDna;
    this->init(obj.getAsChar());
}


Dnasequence::~Dnasequence(){
    delete [] m_cstringDna;
    m_cstringDna = NULL;
}


Dnasequence& Dnasequence::operator=(const Dnasequence& obj){
    if(this == &obj)
        return *this;
    delete [] m_cstringDna;
    m_lenCstringDna = obj.m_lenCstringDna;
    this->init(obj.getAsChar());
    return *this;

}


const char* Dnasequence::getAsChar()const{

    return (char*)m_cstringDna;
}


char* Dnasequence::getAsCharNonConst()
{
    return (char*)m_cstringDna;
}


void  Dnasequence::init(const char* cString)
{
    size_t i;
    m_cstringDna =new Nucleotied[m_lenCstringDna+1];
    for(i=0;i<m_lenCstringDna;i++)
    {
        m_cstringDna[i]= cString[i];
    }
}


std::ostream& operator <<(std::ostream& cout,const Dnasequence &str1){
    cout<<"the string: "<<str1.getAsChar()<<"\n";
    return cout;
}


size_t Dnasequence::length()const
{
    return m_lenCstringDna;
}



bool operator ==(const Dnasequence&obj, const Dnasequence&_obj)
{
    return strcmp(obj.getAsChar(), _obj.getAsChar()) == 0;
}


bool operator !=(const Dnasequence&obj,const Dnasequence&_obj ) {
    return strcmp(obj.getAsChar(), _obj.getAsChar()) != 0;
}


Dnasequence::Nucleotied&  Dnasequence::operator[](size_t index)const {
    if (index > m_lenCstringDna - 1)
        throw std::invalid_argument("index not valide");
    return m_cstringDna[index];
}
Dnasequence Dnasequence::slice(size_t start, size_t last)const
{
    size_t j,i;

    if(last>m_lenCstringDna)
        last = m_lenCstringDna;

    if(start>last)
        throw std::invalid_argument("invalid index");

    Dnasequence newDna(last-start);

     for( i=start,j = 0; i<last;i++, j++){
         newDna.m_cstringDna[j] = m_cstringDna[i];
     }

     return newDna;
}
Dnasequence::Dnasequence(size_t num):m_lenCstringDna(num){
    m_cstringDna = new Nucleotied[num+1];

}

Dnasequence::Nucleotied Dnasequence::Nucleotied::match(){
    if(m_c=='A')
        return 'T';
    if(m_c=='T')
        return 'A';
    if(m_c=='G')
        return 'C';
    return 'G';

}
Dnasequence Dnasequence::pairingDna(){

    size_t j,i;

    Dnasequence newDna(m_lenCstringDna);

    for(i=0,j=m_lenCstringDna-1;i<m_lenCstringDna;i++,j--)
    {
        newDna[j] = m_cstringDna[i].match();
    }
    return newDna;

}

size_t Dnasequence::find(const Dnasequence&obj,size_t index)const{

    std::string Dna = getAsChar();
    std::string subDna = obj.getAsChar();
    size_t index_= Dna.find(subDna,index);
    if(index_ == std::string::npos)
        return m_lenCstringDna;
    return index_;
}
size_t Dnasequence::count(const Dnasequence&obj)const
 {
    return findall(obj).size();
 }
std::list<size_t > Dnasequence::findall(const Dnasequence&obj)const
{
    std::list<size_t > arr_indexes;
    size_t index = find(obj);

    while(index!=m_lenCstringDna)
    {
        arr_indexes.push_back(index);
        size_t temp = find(obj,index+1);
        index = temp;
    }

    return arr_indexes;
}
void Dnasequence::checkEndCodon(size_t index,std::list<Dnasequence >& listConsensusSequence,
        std::list<size_t> endList)
{

    for(std::list<size_t >::iterator i = endList.begin(); i != endList.end(); i++)
    {
        if(index<*i&&(*i-index)%3 ==0)
        {
            listConsensusSequence.push_back(slice(index,*i+3));
        }
    }


}
std::list<Dnasequence > Dnasequence::consensus()
{
    std::list<Dnasequence> listConsensusSequence;
    std::list<size_t> listIndex = findall((std::string)"ATG");
    std::list<size_t> b = findall((std::string)"TGA");
    std::list<size_t> c = findall((std::string)"TAG");
    std::list<size_t> a=findall((std::string)"TAA");;


    for (std::list<size_t >::iterator i = listIndex.begin();i != listIndex.end(); i++) {

        checkEndCodon(*i, listConsensusSequence, a);
        checkEndCodon(*i, listConsensusSequence, b);
        checkEndCodon(*i,listConsensusSequence,c);

    }

    return listConsensusSequence;
}
void Dnasequence::write(const Iwriter& obj)
{
    obj.write(getAsChar());

}

//class Nucleotid
Dnasequence::Nucleotied::Nucleotied(char c):m_c(c){}


Dnasequence::Nucleotied::Nucleotied():m_c('\0'){}



Dnasequence::Nucleotied& Dnasequence::Nucleotied::operator=(char c){

    if(!isValideChar(c))
        throw std::invalid_argument( "invalid DNA2" );
    m_c = c;
    return *this;
}

const char Dnasequence::Nucleotied::getChar()const{
    return m_c;

}

bool Dnasequence::Nucleotied::isValideChar(char c){
    return c == 'A' || c == 'G' || c == 'T' || c == 'C';
}



////reader//////
Dnasequence::Dnasequence(const Ireader& obj)
{
    if(isValid(obj.get().c_str()))
    {
        m_lenCstringDna = obj.get().length();
        this->init(obj.get().c_str());
    }
}
