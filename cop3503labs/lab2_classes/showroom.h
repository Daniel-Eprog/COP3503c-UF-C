#ifndef SHOWROOM_H
#define SHOWROOM_H

#include <iostream>
#include "vehicle.h"
#include <vector>
#include <string>
using namespace std;



class Showroom
{

    /*private class members*/
    private:

    string showRoomName;
    vector<Vehicle> vehicles;
    int maxCapacity = 0;

    /*public member methods*/
    public:

    Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
    vector<Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();



};

#endif