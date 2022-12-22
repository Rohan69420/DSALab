#define STACKSIZE 100

#include <iostream>

//using class template
template <class T>
class Stack{
    private:
    T stack[STACKSIZE];
    int stack_ptr, item;
    int N;

    public:
    Stack(int d_Size){
        N=d_Size;
        stack_ptr=-1; //init 
    }
    
    void TakeInputToPush(){
            if(!reachedTop()){
                std::cout<<"\nEnter item to push:";
                std::cin>>item;
                push(item);
            }
            else{
                std::cout<<"\nOverflow condition encountered!"<<std::endl;
            }
    }
    void push(T val){
        stack_ptr=stack_ptr+1;
        stack[stack_ptr]=val; //stack[top]=item;
        std::cout<<"\nElement pushed!"<<std::endl;
    }
    void pop(){
        if(stack_ptr<0){
            std::cout<<"\nUnderflow!"<<std::endl;
        }
        else{
        //how to clear the data type
            stack_ptr=stack_ptr-1;
            std::cout<<"\nElement popped!";
        }
    }
    void topCheck(){
         if(!reachedBottom()){
                std::cout<<"\nTop element:   "<<top()<<std::endl;
            }
            else{
                std::cout<<"\nStack Empty!"<<std::endl;
            }
    }
    T top(){
      return stack[stack_ptr];
    }
    bool reachedTop(){
        if(stack_ptr==N-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool reachedBottom(){
        if(stack_ptr==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    int n,x;
   int action;
    char deci;
    std::cout<<"\nEnter required stack size: ";
    std::cin>>n;

    Stack<int> sstack(n);

    do{
        std::cout<<"\nEnter 1 to push\n2 to view top\n3 to pop:\n";
        std::cin>>action;
        switch(action){
            case 1:
           sstack.TakeInputToPush();
            break;
        
            case 2:
           sstack.topCheck();
            break;

            case 3:
            sstack.pop();
            break;

            default:
            std::cout<<"\nPlease enter a valid value.";
            break;

        }
        std::cout<<"Enter 1 to continue operation and 0 to exit";
        std::cin>>deci;

    }while(deci!=0);

    return 0;
}