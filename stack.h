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
    size_t s;
};

template <typename T>
Stack<T>::Stack() : s(0){}

template <typename T>
bool Stack<T>::empty() const{ return s == 0;}

template <typename T>
size_t Stack<T>::size() const{return s;}

template <typename T>
void Stack<T>::push(const T& item){
    stack[s] = item;
    s++;
}

template <typename T>
void Stack<T>::pop(){
    if(s == 0){
        throw std::underflow_error("Empty");
    }
    else{
        s--;
    }   
}

template <typename T>
const T& Stack<T>::top() const{
    if(s == 0){
        throw std::underflow_error("Empty");
    }
    return stack[s];
}








#endif