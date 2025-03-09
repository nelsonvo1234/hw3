#include "stack.h"
#include <iostream>
using namespace std;

int main(){
  Stack<int> stack;
  for(int i = 0; i < 10; i++){
    stack.push(i);
  }
  while(!stack.empty()){
    cout << stack.top() << endl;
    stack.pop();
  }
}