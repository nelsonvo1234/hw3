#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct Comp{
    bool operator()(int x){return x == 8;}
};




int main(int argc, char* argv[])
{

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Heap<int> heap;
    cout << "pushing" << endl;
    for(int i = 10; i >0; i--){
      heap.push(i);
    }
    cout << "printing" << endl;
    while(!heap.empty()){
      cout << heap.top() << endl;
      heap.pop();
    }

    return 0;
    return 0;

}
