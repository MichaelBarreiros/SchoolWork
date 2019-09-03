#include <stdexcept>
#include "Stack.h"

using std::vector;
// Implementation here

template<class T>
Stack<T>::Stack(){
    vector<T> empty;
    this->S = empty;
}

template <class T>
Stack<T>::Stack(vector<T> seq){
    this->S = seq;
}

template <class T>
Stack<T> Stack<T>::push(T t){
    vector<T> pushed(this->S);
    pushed.push_back(t);
    return Stack<T>(pushed);
}

template <class T>
Stack<T> Stack<T>::pop(){
    if (this->S.size() == 0) throw std::out_of_range("Stack is empty, no element to pop");
    vector<T> popped(this->S);
    popped.pop_back();
    return Stack<T>(popped);
}

template <class T>
T Stack<T>::top(){
    if (S.size() == 0) throw std::out_of_range("Stack is empty, no top element");
    return this->S.back();
}

template <class T>
nat Stack<T>::size(){
    return this->S.size();
}

template <class T>
vector<T> Stack<T>::toSeq(){
    return this->S;
}

// Keep this at bottom
template class Stack<CardT>;

