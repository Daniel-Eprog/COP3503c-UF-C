#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    vector<int> myVector(10);
    
    myVector.at(0) = 37;
    cout << myVector.at(0);

    return 0;
}