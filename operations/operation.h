#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Operation {
    protected:
        string equation;
        Operation() : equation("") {}
        Operation(string equation) : equation(equation) {}
    public:
        static Operation* buildFromEquation(string equation);
        inline string name() { return equation; }
        virtual float operate() = 0;
};

class Implementation : public Operation {
    private:
        vector<string> expression;
        map<char,string> variables;
    public:
        Implementation(): Operation(), expression(), variables() {}
        Implementation(std::string equation) : Operation(equation), expression() {}
        static Implementation* buildFromEquation(std::string equation);
        void shuntingYard();
        float operate();
        string processPostFix();
        string operate(std::string operation, std::string operand1, std::string operand2);
        static string clean(std::string equation);
        static string clean2(std::string equation);
};

#endif