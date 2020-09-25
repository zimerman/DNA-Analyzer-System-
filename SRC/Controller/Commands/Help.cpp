#include "Help.h"


std::map<std::string, std::string> Help::m_mapAbout;


void Help::initializeMapAbout()
{
    m_mapAbout.insert(std::pair<std::string, std::string >("new","Creates a new sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("load","Loads the sequence from the file"));
    m_mapAbout.insert(std::pair<std::string, std::string >("count","Returns the number of instances of the sub-sequence within the larger sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("del","Deletes that sequence."));
    m_mapAbout.insert(std::pair<std::string, std::string >("dup","Duplicates the sequence."));
    m_mapAbout.insert(std::pair<std::string, std::string >("find","Finds a sub-sequence within a sequence."));
    m_mapAbout.insert(std::pair<std::string, std::string >("findall","Return all the indices where the sub-sequence appears."));
    m_mapAbout.insert(std::pair<std::string, std::string >("help","Shows a short explanation of command"));
    m_mapAbout.insert(std::pair<std::string, std::string >("len","Prints the length of the sequence."));
    m_mapAbout.insert(std::pair<std::string, std::string >("quit","Prints a goodbye message and exists the application"));
    m_mapAbout.insert(std::pair<std::string, std::string >("rename","Renames the name of the sequence to the new name."));
    m_mapAbout.insert(std::pair<std::string, std::string >("replace","replaces the letter in the index of seqUENCE by new_letter"));
    m_mapAbout.insert(std::pair<std::string, std::string >("save","saves sequence to a file."));
    m_mapAbout.insert(std::pair<std::string, std::string >("slice","Slices the sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("list","Shows all the sequences in the system, by order."));
    m_mapAbout.insert(std::pair<std::string, std::string >("concat","Concatenates dna sequences."));
}


bool Help::isValid(const Paramcommand& param)
{
    return param.getParam().size() <= 2;
}



std::string Help::run(Iwriter &writer, Ireader& reader, dataDNA& containerDna, const Paramcommand& param)
{
    if(!isValid(param))
        throw std::invalid_argument("command not found");

    std::string commands;

    if (param.getParam().size() == 1)
    {
        std::map<std::string, std::string>::iterator iter;
        for(iter = m_mapAbout.begin();iter!=m_mapAbout.end();++iter)
        {
            commands += iter->first + "\n";
        }
        return commands;
    }

    if (m_mapAbout.find(param.getParam()[1])!=m_mapAbout.end())
        return m_mapAbout[param.getParam()[1]];
    else
    {
        return "this coomand not exist";
    }
}

