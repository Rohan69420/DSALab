#include <iostream>
#include <cstring>
#include <stack>

int main(){
    //string for input infix string expression
    std::string infix;
    //string for output postfix expression
    std::string postfix;
    std::stack<char> operatorStack;

    //take the input expression
    std::cout<<"Enter the infix expression to be converted into postfix:";
    std::cin>>infix;
    for (int i=0;i<infix.length();i++){
        switch(infix[i]){
            case '+':
            break;
            case :
            break;
        }

    }




    return 0;
}