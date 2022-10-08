/*
Esteban Medero COP3503c Project 1 - Templated Linked List
October 9, 2022
in this project i will be building a data structure called a linked list. a link list is
a non-contiguous data structure where each Node in the List contains the given value and
a pointer to the next value in the list and sometimes the previuos.
for this specific implementation we will be creating a doubly linked list.
*/

//////////////////*BEGIN PROGRAM*/////////////////////

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename LLType>
class LinkedList
{
    public:
        ///////*struct for Node Information*///////
        struct Node
        {
            LLType data;
            Node* next;
            Node* prev;
        };

        ///////*CONSTRUCTORS/DESTRUCTORS*///////
        LinkedList();
        LinkedList(const LinkedList<LLType>& list);
        ~LinkedList();

        ///////*BEHAVIOR*//////
        void PrintForward() const;
        void PrintReverse() const;
        void PrintFowardRecursive(const Node * node) const;
        void PrintReverseRecursive(const Node * node) const;

        ///////*ACCESSORS*///////
        unsigned int NodeCount() const;
        void FindAll(vector<Node*>& outdata, const LLType& value) const;
        const Node* Find(const LLType& data) const;
        Node* Find(const LLType& data);
        const Node* GetNode(unsigned int index) const;
        Node* GetNode(unsigned int index);
        Node* Head();
        const Node* Head() const;
        Node* Tail();
        const Node* Tail() const;

        ///////*INSERTION*///////
        void AddHead(const LLType& data);
        void AddTail(const LLType& data);
        void AddNodesHead(const LLType* data, unsigned int count);
        void AddNodesTail(const LLType* data, unsigned int count);
        void InsertAfter(Node* node, const LLType& data);
        void InsertBefore(Node* node, const LLType& data);
        void InsertAt(const LLType& data, unsigned int index);

        ///////*REMOVAL*///////
        bool RemoveHead();
        bool RemoveTail();
        unsigned int Remove(const LLType& data);
        bool RemoveAt(unsigned int index);
        void Clear();
    
        ///////*OPERATORS*///////
        const LLType& operator[](unsigned int index) const;
        LLType& operator[](unsigned int index);
        bool operator==(const LinkedList<LLType>& rhs) const;
        LinkedList<LLType>& operator=(const LinkedList<LLType>& rhs);

    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        unsigned int numberNodes = 0;
};

///////////////////*BEGIN PART 1*//////////////////////////

/*default class constructor*/
template <typename LLType>
LinkedList<LLType>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

/*destructor*/
template<typename LLType>
LinkedList<LLType>::~LinkedList()
{
    /*iterates though linked list and deletes all allocated memory*/
    Node* currentNode = this->head;
    while(currentNode != nullptr)
    {
        Node* deleteNode = currentNode;
        currentNode = currentNode->next;
        delete deleteNode;
    }
}

/*return number of nodes*/
template<typename LLType>
unsigned int LinkedList<LLType>::NodeCount() const
{
    return this->numberNodes;
}

/*Adds a new node to the front of the list*/
template<typename LLType>
void LinkedList<LLType>::AddHead(const LLType& data)
{
    /*if first node is being added creates new node for head and tail*/
    if(this->numberNodes == 0)
    {
        this->tail = new Node;
        this->head = this->tail;
        tail->data = data;
        tail->next = nullptr;
        tail->prev = nullptr;
        this->numberNodes += 1;
    }
    else
    {
        Node* currentNode = this->tail;
        Node* previousNode = nullptr;
        while(currentNode != nullptr)
        {
            previousNode = currentNode;
            currentNode = currentNode->prev;
        }
        /*creates a deep copy of the previous head node*/
        currentNode = new Node;
        previousNode->prev = currentNode;
        currentNode->data = data;
        currentNode->next = previousNode;
        currentNode->prev = nullptr;
        this->head = currentNode;
        
        /*increment node count*/
        this->numberNodes += 1;
    }
}

/*Adds a new node the the back of the list*/
template<typename LLType>
void LinkedList<LLType>::AddTail(const LLType& data)
{
    if(this->numberNodes == 0)
    {
        this->head = new Node;
        this->tail = this->head;
        head->data = data;
        head->next = nullptr;
        head->prev = nullptr;
        this->numberNodes += 1;
    }
     else
    {
        Node* currentNode = this->head;
        Node* previousNode = nullptr;
        while(currentNode != nullptr)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        /*creates a deep copy of the previous head node*/
        currentNode = new Node;
        previousNode->next = currentNode;
        currentNode->data = data;
        currentNode->next = nullptr;
        currentNode->prev = previousNode;
        this->tail = currentNode;
        
        /*increment node count*/
        this->numberNodes += 1;
    }

}

/*prints linked list from front "head" to back "tail"*/
template<typename LLType>
void  LinkedList<LLType>::PrintForward() const
{
    Node* currentNode = this->head;
    while(currentNode != nullptr)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
    
}

/*prints linked list from back "tail" to front "head"*/
template<typename LLType>
void LinkedList<LLType>::PrintReverse() const
{
    Node* currentNode = this->tail;
    while(currentNode != nullptr)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}

/*Adds an array of nodes to head of linked list maintaing original order*/
template<typename LLType>
void LinkedList<LLType>::AddNodesHead(const LLType* data, unsigned int count)
{
    for(size_t i = 1; i < count + 1; i++)
    {
        this->AddHead(data[count - i]);
    }

}

/*Adds an array of nodes to tail of linked list maintaing original order*/
template<typename LLType>
void LinkedList<LLType>::AddNodesTail(const LLType* data, unsigned int count)
{
     for(size_t i = 1; i < count + 1; i++)
    {
        this->AddTail(data[count - i]);
    }
}

/////////////////////////*END PART 1*//////////////////////////////

///////////////////////*BEGING PART 2*/////////////////////////////

/*returns a pointer to the head of the linked list*/
template<typename LLType>
typename LinkedList<LLType>::Node* LinkedList<LLType>::Head()
{
    return this->head;
}

/*returns a pointer to the tail of the linked list*/
template<typename LLType>
typename LinkedList<LLType>::Node* LinkedList<LLType>::Tail()
{
    return this->tail;
}

/*returns node at a given index*/
template<typename LLType>
typename LinkedList<LLType>::Node* LinkedList<LLType>::GetNode(unsigned int index)
{
   if(index > this->numberNodes - 1)
   {
      throw std::out_of_range("No such index");
   }
    Node* currentNode = this->head;
    for(size_t i = 0; i < index; i++)
    {
        currentNode = currentNode->prev;
    }
    return currentNode;
}

template<typename LLType>
const typename LinkedList<LLType>::Node* LinkedList<LLType>::GetNode(unsigned int index) const
{
   if(index > this->numberNodes - 1)
   {
      throw std::out_of_range("No such index");
   }
    Node* currentNode = this->head;
    for(size_t i = 0; i < index; i++)
    {
        currentNode = currentNode->prev;
    }
    return currentNode;
}

/*returns the node value at a given index using the [] operator i.e. linkedlist[index]*/
template<typename LLType>
LLType& LinkedList<LLType>::operator[](unsigned int index)
{
    return this->GetNode(index)->data;
}

/*returns a pointer to the node with value of passed in parameter*/
template<typename LLType>
typename LinkedList<LLType>::Node* LinkedList<LLType>::Find(const LLType& data)

{
    Node* currentNode = this->head;
    while(currentNode != nullptr)
    {
        if(currentNode->data == data)
        {
            return currentNode;
        }
        else
        {
            currentNode = currentNode->prev;
        }
    }

    return nullptr;
}

template<typename LLType>
const typename LinkedList<LLType>::Node* LinkedList<LLType>::Find(const LLType& data) const
{
    Node* currentNode = this->head;
    while(currentNode != nullptr)
    {
        if(currentNode->data == data)
        {
            return currentNode;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }

    return nullptr;
}

/*adds pointers to nodes with passed in parameter value to vector of node pointers*/
template<typename LLType>
void LinkedList<LLType>::FindAll(vector<Node*>& outData, const LLType& value) const
{
    Node* currentNode = this->head;
    while(currentNode != nullptr)
    {
        if(currentNode->data == value)
        {
            outData.push_back(currentNode);
            currentNode = currentNode->next;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
}

/*copy constructor */
template<typename LLType>
LinkedList<LLType>::LinkedList(const LinkedList<LLType>& list)
{
    Node* currentNode = list.head;
    /*starts at the head of node to be copied and adds a new node to the new list starting from the tail to kepp original order*/
    while(currentNode != nullptr)
    {
        this->AddTail(currentNode->data);
        currentNode = currentNode->next;
    }
}

template<typename LLType>
LinkedList<LLType>& LinkedList<LLType>::operator=(const LinkedList<LLType>& rhs)
{
    /*frees up linked list by deleting all nodes*/
    this->numberNodes = 0;
    Node* currentNode = this->head;
    while(currentNode != nullptr)
    {
        Node* deleteNode = currentNode;
        currentNode = currentNode->next;
        delete deleteNode;
    }
    
    currentNode = rhs.head;
    /*starts at the head of node to be copied and adds a new node to the new list starting from the tail to kepp original order*/
    while(currentNode != nullptr)
    {
        this->AddTail(currentNode->data);
        currentNode = currentNode->next;
    }

    return *this;
}

///////////////////////*END PART 2*/////////////////////////////
#endif
