/*
Esteban Medero COP3503c Lab3 - Array Based Queue
October 8, 2022
This is part two of lab3 building a dynamically allocated array based queue.
a queue is a data structure that follows the First In First Out principle
the next item is added behind the previous item hence the first item remains in 
the front. Think people forming a line.
*/

//////////////////*BEGIN PROGRAM*/////////////////////

#ifndef ABQ_H
#define ABQ_H

#include <iostream>
#include <string>

using namespace std;

//Declare template class 
template <typename ABQType>
class ABQ
{
   
    //Declare private variables
    private:
        float scaleFactor = 2.0f;
        ABQType *queueArray = nullptr;
        int currentSize = 0;
        int queueIndex = 0;
        int maximumCapacity = 1;

    //Declare public class methods
    public:
        ABQ();
        ABQ(int capacity, float scale);
        ABQ(const ABQ &rhs);
        ABQ& operator=(const ABQ &rhs);
        ~ABQ();
        void enqueue(ABQType data);
        ABQType dequeue();
        ABQType peek();
        int getSize();
        int getMaxCapacity();
        ABQType* getData();

};

//default constructor
template <typename ABQType>
ABQ<ABQType>::ABQ()
{
    currentSize = 0;
    scaleFactor = 2.0f;
    maximumCapacity = 1;
    queueArray = new ABQType[maximumCapacity];
}

//overloaded constructor
template <typename ABQType>
ABQ<ABQType>::ABQ(int capacity, float scale)
{
    currentSize = 0;
    scaleFactor = scale;
    maximumCapacity = capacity;
    queueArray = new ABQType[maximumCapacity];
}
        
//copy constructor
template <typename ABQType>
ABQ<ABQType>::ABQ(const ABQ &rhs)
{
    this->currentSize = rhs.currentSize; //sets current size to right hand side
    this->maximumCapacity = rhs.maximumCapacity; // sets max capacity to right hand side
    this->queueArray = new ABQType[rhs.maximumCapacity]; //allocates space for a new queue with size of right hand side
    //copys right hand side values into new queue one by one "deep copy"
    for(int i = 0; i < maximumCapacity; ++i)
    {
        this->queueArray[i] = rhs.queueArray[i];
    }
}

//overloaded copy operator
template <typename ABQType>
ABQ<ABQType>& ABQ<ABQType>::operator=(const ABQ &rhs)
{
    this->currentSize = rhs.currentSize; //sets current size to right hand side
    this->maximumCapacity = rhs.maximumCapacity;// sets max capacity to right hand side
    delete this->queueArray; //ensures queue to is clear for copy
    this->queueArray = new ABQType[rhs.maximumCapacity]; //allocates memory on queue
    //copys right hand side values into new queue one by one "deep copy"
    for(int i = 0; i < maximumCapacity; ++i)
    {
        this->queueArray[i] = rhs.queueArray[i];
    }
    
    //return new copied queue
    return *this;
}

//destructor deallocates space when class object goes out of scope
template <typename ABQType>
ABQ<ABQType>::~ABQ()
{
    delete[] this->queueArray;
}

//push method adds new item to the stack
template <typename ABQType>
void ABQ<ABQType>::enqueue(ABQType data)
{
    //reallocates space if queue is at capacity
    if(this->getSize() == this->getMaxCapacity())
    {
        //allocates new space for temp queue increased by scale factor
        ABQType* tempQueue = new ABQType[static_cast<int>(this->getSize() * this->scaleFactor)];
        //performs one by one deep copy
        for(int i = 0; i < this->getSize(); ++i)
        {
            tempQueue[i] = this->queueArray[i];
        }
        //adds last value into new array
        tempQueue[this->getSize()] = data;
        //increases maximum capacity 
        this->maximumCapacity *= this->scaleFactor;
        //deletes memory allocated for the queue array
        delete[] this->queueArray;
        //assigns queueArray pointer to the temp queue
        this->queueArray = tempQueue;
        //increases current size by 1
        this->currentSize++;
    }
    else
    {
        //adds new element and increases size by 1
        this->queueArray[this->getSize()] = data;
        this->currentSize++;
    }

}

//removes element from the array and adjusts size if necessary
template <typename ABQType>
ABQType ABQ<ABQType>::dequeue()
{
    //throws runtime error if queue is empty
    if(this->getSize() <= 0)
    {
        throw std::runtime_error("Queue is empty!");
    }
    //saves local variable with value of last in
    ABQType frontValue = this->queueArray[this->queueIndex];
    //removes size of array by one
    this->currentSize -= 1;
    this->queueIndex += 1;
    //if size of array is less than half readjusts size
    if(this->getSize() < (this->getMaxCapacity()/scaleFactor))
    {
        //allocate temp queue with memory size of current number of elements
        ABQType* tempQueue = new ABQType[this->getSize()];
        //performs deep copy
        for(int i = 0; i < this->getSize(); ++i)
        {
            tempQueue[i] = this->queueArray[i + this->queueIndex];
        }
        //reset queue index
        this->queueIndex = 0;
        //readjusts maximum size by scale factor
        this->maximumCapacity = this->maximumCapacity/scaleFactor;
        //deallocates original array
        delete[] this->queueArray;
        //assigns original array to temp queue
        this->queueArray = tempQueue;
    } 
    
    //returns value thats been popped off
    return frontValue;

}

//looks at top value without removing it
template <typename ABQType>
ABQType ABQ<ABQType>::peek()
{
    //throws runtime error if queue is empty
    if(this->getSize() <= 0)
    {
        throw std::runtime_error("Queue is empty!");
    }
    //returns value of top value
    return this->queueArray[this->queueIndex];
}

//returns current size of array
template <typename ABQType>
int ABQ<ABQType>::getSize()
{
    return this->currentSize;
}

//returns maximum capacity 
template <typename ABQType>
int ABQ<ABQType>::getMaxCapacity()
{
    return this->maximumCapacity;
}

//returns queue array
template <typename ABQType>
ABQType* ABQ<ABQType>::getData()
{
    return this->queueArray;
}

//////////////////*END PROGRAM*/////////////////////

#endif