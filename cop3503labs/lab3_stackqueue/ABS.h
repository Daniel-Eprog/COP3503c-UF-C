/*
Esteban Medero COP3503c Lab3 - Array Based Stack
October 8, 2022
This is part one of lab3 building a dynamically allocated array based stack
a stack is a data structure that follows the First In Last Out principle (FILO)
new items are stacked on top of the previous hence the first one in ends up on the 
bottom. Items are then popped off from the top. 
*/

//////////////////*BEGIN PROGRAM*/////////////////////

#ifndef ABS_H
#define ABS_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Declare template class 
template <typename ABSType>
class ABS
{

    //Declare private variables
    private:
        float scaleFactor = 2.0f;
        ABSType *stackArray = nullptr;
        int currentSize = 0;
        int maximumCapacity = 2;

    //Declare public class methods
    public:
        ABS();
        ABS(int capacity, float scale);
        ABS(const ABS &rhs);
        ABS& operator=(const ABS &rhs);
        ~ABS();
        void push(ABSType data);
        ABSType pop();
        ABSType peek();
        int getSize();
        int getMaxCapacity();
        ABSType* getData();

};

//default constructor
template <typename ABSType>
ABS<ABSType>::ABS()
{
    currentSize = 0;
    scaleFactor = 2.0f;
    maximumCapacity = 1;
    stackArray = new ABSType[maximumCapacity];
}

//overloaded constructor
template <typename ABSType>
ABS<ABSType>::ABS(int capacity, float scale)
{
    currentSize = 0;
    scaleFactor = scale;
    maximumCapacity = capacity;
    stackArray = new ABSType[maximumCapacity];
}
        
//copy constructor
template <typename ABSType>
ABS<ABSType>::ABS(const ABS &rhs)
{
    this->currentSize = rhs.currentSize; //sets current size to right hand side
    this->maximumCapacity = rhs.maximumCapacity; // sets max capacity to right hand side
    this->stackArray = new ABSType[rhs.maximumCapacity]; //allocates space for a new stack with size of right hand side
    //copys right hand side values into new stack one by one "deep copy"
    for(int i = 0; i < maximumCapacity; ++i)
    {
        this->stackArray[i] = rhs.stackArray[i];
    }
}

//overloaded copy operator
template <typename ABSType>
ABS<ABSType>& ABS<ABSType>::operator=(const ABS &rhs)
{
    this->currentSize = rhs.currentSize; //sets current size to right hand side
    this->maximumCapacity = rhs.maximumCapacity;// sets max capacity to right hand side
    delete this->stackArray; //ensures stack to is clear for copy
    this->stackArray = new ABSType[rhs.maximumCapacity]; //allocates memory on stack
    //copys right hand side values into new stack one by one "deep copy"
    for(int i = 0; i < maximumCapacity; ++i)
    {
        this->stackArray[i] = rhs.stackArray[i];
    }
    
    //return new copied stack
    return *this;
}

//destructor deallocates space when class object goes out of scope
template <typename ABSType>
ABS<ABSType>::~ABS()
{
    delete[] this->stackArray;
}

//push method adds new item to the stack
template <typename ABSType>
void ABS<ABSType>::push(ABSType data)
{
    //reallocates space if stack is at capacity
    if(this->getSize() == this->getMaxCapacity())
    {
        //allocates new space for temp stack increased by scale factor
        ABSType* tempStack = new ABSType[static_cast<int>(this->getSize() * this->scaleFactor)];
       
        //performs one by one deep copy
        for(int i = 0; i < this->getSize(); ++i)
        {
            tempStack[i] = this->stackArray[i];
        }

        //adds last value into new array
        tempStack[this->getSize()] = data;

        //increases maximum capacity 
        this->maximumCapacity *= this->scaleFactor;
        //deletes memory allocated for the stack array
        delete[] this->stackArray;
        //assigns stackArray pointer to the temp stack
        this->stackArray = tempStack;
        //increases current size by 1
        this->currentSize++;
    }
    else
    {
        //adds new element and increases size by 1
        this->stackArray[this->getSize()] = data;
        this->currentSize++;
    }

}

//removes element from the array and adjusts size if necessary
template <typename ABSType>
ABSType ABS<ABSType>::pop()
{
    //throws runtime error if stack is empty
    if(this->getSize() <= 0)
    {
        throw std::runtime_error("Stack is empty!");
    }
    //saves local variable with value of last in
    ABSType topValue = this->stackArray[this->getSize() - 1];
    //removes size of array by one
    this->currentSize -= 1;
    //if size of array is less than half readjusts size
    if(this->getSize() < (this->getMaxCapacity()/scaleFactor))
    {
        //allocate temp stack with memory size of current number of elements
        ABSType* tempStack = new ABSType[this->getSize()];
        //performs deep copy
        for(int i = 0; i < this->getSize(); ++i)
        {
            tempStack[i] = this->stackArray[i];
        }
        //readjusts maximum size by scale factor
        this->maximumCapacity = this->maximumCapacity/this->scaleFactor;
        //deallocates original array
        delete[] this->stackArray;
        //assigns original array to temp stack
        this->stackArray = tempStack;
    } 
    
    //returns value thats been popped off
    return topValue;

}

//looks at top value without removing it
template <typename ABSType>
ABSType ABS<ABSType>::peek()
{
    //throws runtime error if stack is empty
    if(this->getSize() <= 0)
    {
        throw std::runtime_error("Stack is empty!");
    }
    //returns value of top value
    return this->stackArray[this->getSize() - 1];
}

//returns current size of array
template <typename ABSType>
int ABS<ABSType>::getSize()
{
    return this->currentSize;
}

//returns maximum capacity 
template <typename ABSType>
int ABS<ABSType>::getMaxCapacity()
{
    return this->maximumCapacity;
}

//returns stack array
template <typename ABSType>
ABSType* ABS<ABSType>::getData()
{
    return this->stackArray;
}

//////////////////*END PROGRAM*/////////////////////

#endif