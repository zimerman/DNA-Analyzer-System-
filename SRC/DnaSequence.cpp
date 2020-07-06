//
// Created by a on 6/1/20.
//

#include "DnaSequence.h"
#include "string.h"
#include "string"
#include "ostream"
#include "stdlib.h"
#include <list>


DnaSequence::DnaSequence(const char* str)
{
    if(!check_validation(str)) {
        throw std::invalid_argument("this value not match to dna");
    }
    m_len_string_dna = strlen(str);
    this->init(str);
}


DnaSequence::DnaSequence(size_t len)
{

    m_len_string_dna = len;
    m_cstring_dna = new Nucleotide[len+1];
}

DnaSequence::DnaSequence(const std::string& str)
{
    if(!check_validation(str.c_str()))
    {
        throw std::invalid_argument("this value not match to dna");
    }
    m_len_string_dna = str.length();
    this->init(str.c_str());
}

DnaSequence::DnaSequence(const DnaSequence& obj)
{
    m_len_string_dna = obj.m_len_string_dna;
    this->init(obj.cast_char());
}

DnaSequence::~DnaSequence()
{
    delete[] m_cstring_dna;
    m_cstring_dna = NULL;
}

void DnaSequence::init(const char* str)
{
    if(!(check_validation(str)))
    {
        throw std::invalid_argument("this value not match to dna");
    }
    m_cstring_dna = new Nucleotide[strlen(str)+1];
    for(size_t i=0;i < strlen(str); i++)
    {
        m_cstring_dna[i] = str[i];
    }
}

bool DnaSequence::check_validation(const char *str)
{
    if(!str)
    {
        return false;
    }

    if(!(strspn(str, "ACTG")==strlen(str)))
    {
        return false;
    }
    return true;
}

DnaSequence& DnaSequence::operator=(const DnaSequence& obj)
{
    if(this==&obj)
        return *this;
    delete[] m_cstring_dna;
    this->init(obj.cast_char());
    return *this;
}

std::ostream& operator <<(std::ostream& cout, const DnaSequence& obj)
{
    cout <<"The string is:"<<obj.cast_char()<<"\n";
    cout <<"The len of string is:"<<obj.m_len_string_dna<<"\n";
    return cout;
}

size_t DnaSequence::length()const
{
    return m_len_string_dna;
}

bool operator==(const DnaSequence& obj1, const DnaSequence& obj2)
{
    if(!strcmp(obj1.cast_char(), obj2.cast_char()))
        return true;
    return false;
}

bool operator!=(const DnaSequence& obj1, const DnaSequence& obj2)
{
    if (strcmp(obj1.cast_char(), obj2.cast_char()))
        return true;
    return false;
}

DnaSequence::Nucleotide::Nucleotide(char c)
{
    if(check_validation_nucleotide(c))
    {
        m_c = c;
    }
}

DnaSequence::Nucleotide::Nucleotide():m_c('\0'){}

char DnaSequence::Nucleotide::get_c()const
{
    return m_c;
}

bool DnaSequence::Nucleotide::check_validation_nucleotide(const char str)
{
    if(str != 'A'  and str != 'C' and str != 'T' and str != 'G')
    {
        return false;
    }
    return true;
}

const char* DnaSequence::cast_char()const
{
    return (char*)m_cstring_dna;
}

DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(char c)
{
    if(!check_validation_nucleotide(c))
    {
        throw std::invalid_argument("this value not match to dna");
    }
    m_c = c;
    return *this;
}

DnaSequence::Nucleotide& DnaSequence::operator[](size_t index)const
{
    if(index > m_len_string_dna-1)
    {
        throw std::invalid_argument("this index out of range");
    }
    return m_cstring_dna[index];
}


DnaSequence DnaSequence::slice(size_t start, size_t end)
{
	if( end > m_len_string_dna)
	{
		end=m_len_string_dna;
	}
	if(start > end)
	{
		start = end ;
	}
	DnaSequence dna(end-start);
	size_t i;
	size_t j;
	for(i=start, j=0; i < end ;i++, j++)
	{
		dna[j] = m_cstring_dna[i];
	}
	return dna;
}

DnaSequence DnaSequence::pairing()
{
	DnaSequence dna(m_len_string_dna);
	size_t j;
	size_t i;
	for(i=0, j=m_len_string_dna-1; i < m_len_string_dna;i++, j--)
	{
		dna[i] = m_cstring_dna[j].match_pair();
	}
	return dna;                   
}

const DnaSequence::Nucleotide DnaSequence::Nucleotide::match_pair()
{
	if(m_c == 'G')
		return 'C';
	if(m_c =='C')
		return 'G';
	if(m_c =='T')
		return 'A';
	return 'T';
}

size_t DnaSequence::find(const DnaSequence& sub_dna)
{
	std::string strs(sub_dna.cast_char());
	std::string strb(cast_char());
	size_t index = strb.find(strs);
	if(index == std::string::npos)
	{
	    return m_len_string_dna;
	}
    return index;

}

size_t DnaSequence::count(const DnaSequence& sub_dna)
{
    return findAll(sub_dna).size();
}

std::list<size_t> DnaSequence::findAll(const DnaSequence& sub_dna)
{
    size_t i=0;
    std::list<size_t> mylist;
    size_t ind = find(sub_dna);
    if(ind != m_len_string_dna)
        mylist.push_back(ind);
    size_t temp;
    for(i=1;ind!= m_len_string_dna && i < m_len_string_dna; i++)
    {
        temp = slice(i, m_len_string_dna).find(sub_dna)+i;
        if(ind != temp && temp!= m_len_string_dna)
        {
            mylist.push_back(temp);
        }
        ind = temp;
    }
    return mylist;
}


/*std::list<size_t> DnaSequence::FindConsensusSequences()
{
	std::list<size_t> mylist;
    std::list<size_t> list_start_codon;
    std::list<size_t> list_end1_codon;
    std::list<size_t> list_end2_codon;
    std::list<size_t> list_end3_codon;
    list_start_codon = findAll("ATG");
    list_end1_codon = findAll("TAG");
    list_end2_codon = findAll("TAA");
    list_end2_codon = findAll("TGA");
    for(std::list<size_t>::iterator iter = list_start_codon.begin(); iter!= list_start_codon.end();iter++)
    {
        for(std::list<size_t>::iterator iter1 = list_end1_codon.begin(); iter1!= list_end1_codon.end();iter1++)
        {
            if(*iter < *iter1 and (*iter1-*iter)%3==0)
            {
                mylist.push_back(*iter);
            }

        }
        for(std::list<size_t>::iterator iter2 = list_end2_codon.begin(); iter2!= list_end2_codon.end();iter2++)
        {
            if(*iter < *iter2 and (*iter2-*iter)%3==0)
            {
                mylist.push_back(*iter);
            }
        }
        for(std::list<size_t>::iterator iter3 = list_end3_codon.begin(); iter3!= list_end3_codon.end();iter3++)
        {
            if(*iter < *iter3 and (*iter3-*iter)%3==0)
            {
                mylist.push_back(*iter);
            }
        }
    }
    return mylist;
}*/


void DnaSequence::write(const Iwriter& dna)
{
    dna.write(this->cast_char());
}



std::list<size_t> DnaSequence::FindConsensusSequences()
{
    std::list<size_t> mylist;
    std::list<size_t> list_start_codon;
    std::list<size_t> list_end1_codon;
    std::list<size_t> list_end2_codon;
    std::list<size_t> list_end3_codon;
    list_start_codon = findAll("ATG");
    list_end1_codon = findAll("TAG");
    list_end2_codon = findAll("TAA");
    list_end2_codon = findAll("TGA");
    std::list<size_t>::iterator it;
    it = list_end1_codon.end();
    list_end1_codon.splice(it, list_end2_codon);
    it = list_end1_codon.end();
    list_end1_codon.splice(it, list_end3_codon);
    for(std::list<size_t>::iterator iter = list_start_codon.begin(); iter!= list_start_codon.end();iter++)
    {
        for(std::list<size_t>::iterator iter1 = list_end1_codon.begin(); iter1!= list_end1_codon.end();iter1++)
        {
            if(*iter < *iter1 and (*iter1-*iter)%3==0)
            {
                mylist.push_back(*iter);
            }

        }
    }
    return mylist;
}






/*size_t* DnaSequence::findAll(const DnaSequence& sub_dna)
{
	size_t i=0;
	size_t j=0;
	size_t* arr_ind = new size_t[count(sub_dna)];
	size_t ind = find(sub_dna);
	if(ind != m_len_string_dna)
		arr_ind[j++] = ind;
	size_t temp;
	for(i=1;ind!= m_len_string_dna && i < m_len_string_dna; i++)
	{
		temp = slice(i, m_len_string_dna).find(sub_dna)+i;
		if(ind != temp && ind!= m_len_string_dna)
        {
			arr_ind[j++] = temp;
		}
		ind = temp;
	}
	return arr_ind;
}

size_t DnaSequence::count(const DnaSequence& sub_dna)
{
    size_t i=0;
    size_t count = 0;
    size_t ind = find(sub_dna);
    if(ind != m_len_string_dna)
    {
        count ++;
    }
    size_t temp;
    for(i=1; ind != m_len_string_dna and i < m_len_string_dna; i++)
    {
        temp = slice(i, m_len_string_dna).find(sub_dna)+i;
        if(ind != temp and temp != m_len_string_dna)
        {
            count ++;
            ind = temp;
        }
    }
    return count;
}*/


DnaSequence::DnaSequence(const Ireader& obj)
{
    //new (this)DnaSequence(obj.getData());
    if(!check_validation(obj.getData().c_str()))
    {
        throw std::invalid_argument("this value not match to dna");
    }
    m_len_string_dna = obj.getData().length();
    this->init(obj.getData().c_str());
}
