#include <iostream>
#include <stack>

using namespace std;

int main(){
//creating a stack
stack<int> stacked;
stacked.push(1);
stacked.push(2);
stacked.push(3);
stacked.push(4);

//printing top element on stack
printf("%d\n",stacked.top());


//popping elements from stack
stacked.pop();

//printing after popping
printf("%d\n",stacked.top());

stacked.pop();
return 0;


}