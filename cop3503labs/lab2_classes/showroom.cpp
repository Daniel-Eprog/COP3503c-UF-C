#include <iostream>
#include "showroom.h"

/*default constructor with optional parameters*/
Showroom::Showroom(string name, unsigned int capacity)
{
    showRoomName = name;
    maxCapacity = capacity;
}

/*adds new vehicles to showroom*/
void Showroom::AddVehicle(Vehicle v)
{
    if(vehicles.size() == maxCapacity)
    {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    }
    else
    {
        vehicles.push_back(v);
    }
}

/*returns vector of vehicles in showroom*/
vector<Vehicle> Showroom::GetVehicleList()
{
    return vehicles;
}

/*shows inventory of showroom*/
void Showroom::ShowInventory()
{
    if(vehicles.size() <= 0)
    {
        cout << showRoomName << " is empty!" << endl;
    }
    else
    {
        cout << "Vehicles in " << showRoomName << endl;
        for(size_t i = 0; i < vehicles.size(); i++)
        {
            vehicles.at(i).Display();
        }
        cout << "\n";
    }
}

/*shows total value of vehicles in showroom*/
float Showroom::GetInventoryValue()
{
    float inventoryVal;

    for(size_t i = 0; i < vehicles.size(); i++)
    {
        inventoryVal += vehicles.at(i).GetPrice();
    }

    return inventoryVal;
}