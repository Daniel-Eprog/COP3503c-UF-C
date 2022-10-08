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
    LinkedList<int> secondList = firstList;
    firstList.PrintForward();
    cout << "break" << endl;
    secondList.PrintForward();
    LinkedList<int> thirdList;
    thirdList.AddHead(3);
    thirdList.PrintForward();
    secondList = thirdList;
    secondList.PrintForward();
    thirdList = firstList;
    thirdList.PrintForward();

    

    return 0;
}