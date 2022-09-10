#include "dealership.h"

/*Default constructor with optional parameters*/
 Dealership::Dealership(string name, unsigned int capacity)
 {
    dealershipName = name;
    dealershipCapacity = capacity;
 }

/*adds a showroom to dealerships showroom vector*/
void Dealership::AddShowroom(Showroom s)
{
    if(showrooms.size() == dealershipCapacity)
    {
        cout << "Dealership is full, can't add another showroom!" << endl;
    }
    else
    {
        showrooms.push_back(s);
    }
}


/*returns average price of the dealerships inventory*/
float Dealership::GetAveragePrice()
{
    float sum = 0;
    int numVehicles = 0;

    for(size_t i = 0; i < showrooms.size(); i++)
    {
        sum += showrooms.at(i).GetInventoryValue();
        numVehicles += showrooms.at(i).GetVehicleList().size();
    }

    return sum/numVehicles;
}
    
/*show inventory of current dealership and average price of vehicles present*/
void Dealership::ShowInventory()
{
   if(showrooms.size() <= 0)
   {
      cout << dealershipName << " is empty!" << endl;
      cout << "Average car price: $0.00";
   }
   else
   {
       for(size_t i = 0; i < showrooms.size(); i++)
       {
           showrooms.at(i).ShowInventory();
       }
       
       cout << "Average car price: $" << GetAveragePrice();
   }
}