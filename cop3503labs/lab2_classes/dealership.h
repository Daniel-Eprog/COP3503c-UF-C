#ifndef DEALERSHIP_H
#define DEALERSHIP_H

#include "vehicle.h"
#include "showroom.h"

class Dealership
{
    /*private class members*/
    private:

    vector<Showroom> showrooms;
    string dealershipName;
    int dealershipCapacity = 0;
  

    /*public member methods*/
    public:

    Dealership(string name = "Generic Dealership", unsigned int capacity = 0);
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();


};


#endif