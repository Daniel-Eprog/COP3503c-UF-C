/*
Esteban Medero COP3503c Lab3 - Array Based Queue/Array Based Stack Testing Code
October 8, 2022
This is part three of lab 3 where we will take the array based Stack and Queue, set 
testing parameters, and record the run time of each scenario.
*/

//////////////////*BEGIN PROGRAM*/////////////////////


#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "abs.h"
#include "abq.h"

using namespace std;

int main()
{
    
    vector<float> scale{1.5, 2.0, 3.0, 10.0, 100.0};
    vector<int> numberOfElements{10000000, 30000000, 50000000, 75000000, 100000000};
    float totalTime = 0.0;
    
    cout << "---------Stack--------" << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            ABS<int> stack(2, scale.at(i));
            float start = clock();
            for(int k = 0; k < numberOfElements.at(j); k++)
            {
                stack.push(k);
            }
            float end = clock();
            float executionTime = end - start;
            totalTime += executionTime;
            cout << "Scale: " << scale.at(i) << "  N:  " << numberOfElements.at(j) << "  Pushing Time:  " << executionTime/1000 << "s" << endl;
            start = clock();
            for(int k = 0; k < numberOfElements.at(j); k++)
            {
                stack.pop();
            }
            end = clock();
            executionTime = end - start;
            totalTime += executionTime;
            cout << "Scale: " << scale.at(i) << "  N:  " << numberOfElements.at(j) << "  Popping Time:  " << executionTime/1000 << "s" << endl;
        }
    }

    cout << "---------Queue--------" << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            ABQ<int> queue(2, scale.at(i));
            float start = clock();
            for(int k = 0; k < numberOfElements.at(j); k++)
            {
                queue.enqueue(k);
            }
            float end = clock();
            float executionTime = end - start;
            totalTime += executionTime;
            cout << "Scale: " << scale.at(i) << "  N:  " << numberOfElements.at(j) << "  Enqueue Time:  " << executionTime/1000 << "s" << endl;
            start = clock();
            for(int k = 0; k < numberOfElements.at(j); k++)
            {
                queue.dequeue();
            }
            end = clock();
            executionTime = end - start;
            totalTime += executionTime;
            cout << "Scale: " << scale.at(i) << "  N:  " << numberOfElements.at(j) << "  Dequeue Time:  " << executionTime/1000 << "s" << endl;
        }
    }

    cout << "Total Execution Time: " << totalTime/1000 << "s" << endl;
    
    return 0;

};

//////////////////*END PROGRAM*/////////////////////
