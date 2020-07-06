//
// Created by a on 7/5/20.
//

#ifndef CODE_PARAMCOMMAND_H
#define CODE_PARAMCOMMAND_H
#include <vector>
#include <string>
class ParamCommand
{
public:
    ParamCommand(std::string phrase);
    std::vector<std::string> getParam()const;
private:
    std::vector<std::string> m_param_vec;
};


#endif //CODE_PARAMCOMMAND_H
