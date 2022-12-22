#include <iostream>
#include <stack>
#include <string>

class PrefixConverter
{
private:
    std::string uninvertedInput, inputExpression, contemporaryTop;
    std::string Prefix;
    std::stack<char> opStack;

public:
    PrefixConverter()
    {
        std::cout << "\nEnter the input expression: ";
        std::cin >> uninvertedInput;
        Prefix = "";
        contemporaryTop = "";
        inputExpression=inverter(uninvertedInput);
        parser();
        dumpStackSymbol();
        showPrefixResult();
    }
    std::string inverter(std::string inputString){
        std::string inverted ="";
        for (int i=inputString.length()-1;i>=0;i--){
            if(inputString[i]==')'){
                inverted+='(';
            }
            else if(inputString[i]=='('){
                inverted+=')';
            }
            else{
            inverted += inputString[i];
            }
        }
        return inverted;
    }
    void parser()
    {
        for (int i = 0; i < inputExpression.length(); i++)
        {
            std::cout << "Parser data: " << inputExpression[i]; // debug
            Prefixer(inputExpression[i]);
        }
    }
    bool isBraces(char key)
    {
        if (key == '(' || key == ')')
        {
            return true;
        }
        return false;
    }
    void Prefixer(char key)
    {
        if (ispunct(key))
        {
            if (opStack.size() > 0)
            {
                std::cout<<"Stack top= "<< opStack.top();
                if ((precedenceRank(key) <= precedenceRank(opStack.top())) && !isBraces(key))
                {
                    // pop
                    contemporaryTop = opStack.top();
                    Prefix += contemporaryTop;
                    opStack.pop();

                    // push
                    opStack.push(key);
                }
                else if (isBraces(key) && key == ')')
                {
                    while (key != '(')
                    {
                        contemporaryTop = opStack.top();
                        Prefix += contemporaryTop;
                        opStack.pop();
                    }
                }
                else if ((precedenceRank(key) > precedenceRank(opStack.top())) && !isBraces(key)){   //higher precedence
                    opStack.push(key);
                    std::cout<<"New stack top: "<<opStack.top(); //Debugz
                }
            }
            else 
            { // initializer
                opStack.push(key);
            }
        }
        else if ((isalpha(key) || isdigit(key)))
        {
            Prefix += key;
        }
    }
    int precedenceRank(char sym)
    {
        if (sym == '(')
        {
            return 3;
        }
        else if (sym == '^')
        {
            return 2;
        }
        else if (sym == '/' || sym == '*')
        {
            return 1;
        }
        else if (sym == '+' || sym == '-')
        {
            return 0;
        }
        return -1;
    }
    void dumpStackSymbol()
    {
        // dump stack symbol to Prefix expression
        if (opStack.size() != 0)
        {
            while(opStack.size()>0)
            {
                contemporaryTop = opStack.top();
                Prefix += contemporaryTop;
                opStack.pop();
            }
        }
    }
    void showPrefixResult()
    {
        std::cout << "The Prefix expression is: " << inverter(Prefix) << std::endl;
    }
};

int main()
{
    PrefixConverter P;
    return 0;
}