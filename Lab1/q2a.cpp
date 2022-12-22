#include <iostream>
#include <stack>
#include <string>

class PostfixConverter
{
private:
    std::string inputExpression, contemporaryTop;
    std::string PostFix;
    std::stack<char> opStack;

public:
    PostfixConverter()
    {
        std::cout << "\nEnter the input expression: ";
        std::cin >> inputExpression;
        PostFix = "";
        contemporaryTop = "";
        parser();
        dumpStackSymbol();
        showPostfixResult();
    }
    void parser()
    {
        for (int i = 0; i < inputExpression.length(); i++)
        {
            std::cout << "Parser data: " << inputExpression[i]; // debug
            PostFixer(inputExpression[i]);
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
    void PostFixer(char key)
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
                    PostFix += contemporaryTop;
                    opStack.pop();

                    // push
                    opStack.push(key);
                }
                else if (isBraces(key) && key == ')')
                {
                    while (key != '(')
                    {
                        contemporaryTop = opStack.top();
                        PostFix += contemporaryTop;
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
            PostFix += key;
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
        // dump stack symbol to postfix expression
        if (opStack.size() != 0)
        {
            while(opStack.size()>0)
            {
                contemporaryTop = opStack.top();
                PostFix += contemporaryTop;
                opStack.pop();
            }
        }
    }
    void showPostfixResult()
    {
        std::cout << "The postfix expression is: " << PostFix << std::endl;
    }
};

int main()
{
    PostfixConverter P;
    return 0;
}