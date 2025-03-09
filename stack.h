#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> stack;
};

template <typename T>
Stack<T>::Stack(){}

template <typename T>
bool Stack<T>::empty() const{ return stack.size() == 0;}

template <typename T>
size_t Stack<T>::size() const{return stack.size();}

template <typename T>
void Stack<T>::push(const T& item){
    stack.push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(stack.size() == 0){
        throw std::underflow_error("Empty");
    }
    else{
        stack.pop_back();
    }   
}

template <typename T>
const T& Stack<T>::top() const{
    if(stack.size() == 0){
        throw std::underflow_error("Empty");
    }
    return stack[stack.size() - 1];
}

template <typename T>
Stack<T>::~Stack(){

}








#endif