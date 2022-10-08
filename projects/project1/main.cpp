#include <iostream>
#include <string>
#include <vector>
#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList<int> firstList;
    vector<LinkedList<int>::Node *> vectorTest;
    firstList.AddHead(5);
    firstList.AddHead(15);
    firstList.AddHead(25);
    firstList.AddHead(25);
    firstList.AddHead(25);
    firstList.AddHead(5);
    firstList.FindAll(vectorTest, 25);
    cout << vectorTest.size() << endl;

    

    return 0;
}