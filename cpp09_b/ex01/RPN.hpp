#pragma once
#include <stack>
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <cstdlib>


class RPN
{
    public:
        RPN(){}
        RPN(std::string exp);
        RPN(const RPN &other);
        RPN& operator= (const RPN &other);
        ~RPN() {};
        long get_result() {return result;}

    private:
        std::stack<long>   numStack;
        long result;

    
};