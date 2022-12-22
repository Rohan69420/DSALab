#include <iostream>

class PairChecker{
    private:
    std::string inputExpression;
    int counter;

    public:
    PairChecker(){
        std::cout<<"Enter the input mathematical expression: ";
        std::cin>>inputExpression;
        counter=0;
        centralCounter();
        result();
    }
    void centralCounter(){
        for (int i=0; i<inputExpression.length(); i++){
            if(inputExpression[i]=='(')
                counter++;
            if(inputExpression[i]==')')
                counter--;
        }
    }
    void result(){
        if(counter==0){
            std::cout<<"Balanced!";
        }
        else{
            std::cout<<"Not balanced!";
        }
    }
};
int main(){
    PairChecker p;
    return 0;
}