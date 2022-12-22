#include <iostream>
#include <stack>
#include <ctype.h>
#include <math.h>

class Evaluator
{
private:
    std::stack<int> Operands;
    std::string inputExpression;
    int a, b;
    bool first;

public:
    Evaluator()
    {
        first=true;
        std::cout << "Enter the postfix expression to be evaluated: " << std::endl;
        std::cin >> inputExpression;
        parser();
        showResult();
    }

    void parser()
    {
        for (int i = 0; i < inputExpression.length(); i++)
        {
            if (isdigit(inputExpression[i]))
            {
                // pushing into the operands stack
                std::cout << "Digit parsed: " << inputExpression[i];
                Operands.push(inputExpression[i]);
            }
            else if (ispunct(inputExpression[i]))
            {
                // upon encountering operators
                std::cout << "Operator parsed: " << inputExpression[i];
                OperateOperator(inputExpression[i]);
            }
        }
    }
    bool validOperator(char x){
        if (x=='+' || x=='-' || x=='*' || x=='/' || x=='^'){
            return true;
        }
        return false;
    }
    void OperateOperator(char op)
    {
        // use of valid symbol only yet to be implemented
        if (validOperator(op))
        {
            std::cout<<"Operator valid!"<<std::endl;
            if (first){
            b = Operands.top() - int('0');
            }
            else{
                b=Operands.top();
            }
            Operands.pop();
            a = Operands.top() - int('0');
            Operands.pop();
            std::cout<<"A val: "<<a<<" B val: "<<b;
            switch (op)
            {
            case '+':
                Operands.push(a + b);
                break;

            case '-':
                Operands.push(a - b);
                break;

            case '*':
                Operands.push(a * b);
                break;

            case '/':
                Operands.push(a / b);
                break;

            case '^':
                Operands.push(int(pow(double(a), double(b))));
                break;
            }
            first=false;
            std::cout << "Stack new top: " << Operands.top() << " at " << Operands.size();
        }
    }
    void showResult()
    {
        std::cout << "Size of stack: " << Operands.size(); // debug
        std::cout << "The calculated output is: " << Operands.top();
    }
};
int main()
{
    Evaluator eval;
    return 0;
}