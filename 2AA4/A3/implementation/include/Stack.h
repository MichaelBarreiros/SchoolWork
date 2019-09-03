/**
 * \file Stack.h
 * \author Michael Barreiros
 * \brief Defining the stack object. Operations that resemble a stack's push, pop, top
 */
#ifndef A3_STACK_H_
#define A3_STACK_H_

#include "CardTypes.h"
#include <vector>

/**
 * \brief Template class for storing values in a FILO (First in, Last out) stack
 */
template <class T>
class Stack{
    private:
        std::vector<T> S;
    
    public:
        /**
         * \brief Construct a stack
         * \details Creates a new instance of stack thats empty
         */
        Stack();

        /**
         * \brief Constructs a stack
         * \details Creates a new instance of stack that is set up with the same initail elements in Seq
         * \param Seq The inital elements to push on to the stack
         */
        Stack(std::vector<T> Seq);

        /**
         * \brief Creates a new stack by pushing the given value on to the current stack
         * \details Creates a new instance of stack identical to the last one except that 
         * the element t is added to the top
         * \param t The new element of type T to be placed on top of the stack
         * \return A new instance of stack with the element t pushed onto the top of the initial stack
         */
        Stack<T> push(T t);

        /**
         * \brief Creates a new stack by popping the top value off the current stack
         * \details Create a new instance of stack with the same elements as the initial stack but with the top element removed
         * \return A new instance of stack with the last element of the initial stack removed
         * \throw out_of_range The stack is empty and cannot be popped
         */
        Stack<T> pop();

        /**
         * \brief Get the top value of the current stack
         * \details Returns the most recently added element on the current stack
         * \return The top value of type T of the current stack
         * \throw out_of_range The stack is empty and there is no top element
         */
        T top();

        /**
         * \brief Get the size of the current stack
         * \details Returns the number of elements stored in the current stack
         * \return The number of elements on the current stack
         */
        nat size();

        /**
         * \brief Get a sequence representation of the current stack
         * \details Returns a sequence representing the elements in the current stack. Last
         * element of the sequence corresponds to the top of the stack
         * \return The sequence representation of the current stack
         */
        std::vector<T> toSeq();
};
#endif