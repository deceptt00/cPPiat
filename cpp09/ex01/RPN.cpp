#include "RPN.hpp"

bool is_operand (char t)
{
    if (t == '-' || t == '+' || t == '/' || t == '*')
        return true;
    return false;
}

void    processRpn(std::string exp)
{
    if (exp.empty())
        throw std::runtime_error("Error");

    std::stack<float>   numStack;
    std::stringstream   ss_exp(exp);
    std::string         tokenStr;
    char                token;
    float               num;

    while (ss_exp >> tokenStr)
    {
        if (tokenStr.length() != 1)
            throw std::runtime_error("Error");
        token = tokenStr[0];
        if (std::isdigit(token))
            numStack.push(static_cast<float>(token - '0'));
        else if (is_operand(token))
        {
            if (numStack.size() < 2)
                throw std::runtime_error("Error");
            num = numStack.top();
            numStack.pop();
            switch (token)
            {
                case '+':
                    num += numStack.top();
                    break;
                case '-':
                    num = numStack.top() - num;
                    break ;
                case '*':
                    num *= numStack.top();
                    break ;
                case '/':
                    if (num != 0)
                        num = numStack.top() / num;
                    else
                        throw std::runtime_error("Error: can't divide by 0");
                    break ;
                default:
                    break;
            }
            numStack.pop();
            numStack.push(num);
        }
        else
            throw std::runtime_error("Error");
    }
    if (numStack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << numStack.top() << std::endl;
}
