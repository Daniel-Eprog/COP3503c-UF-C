#include <iostream>
#include "vehicle.h"
using namespace std;

/*Defualt constructor*/
Vehicle::Vehicle()
{
    carMake = "COP3503";
    carModel = "Rust Bucket";
    carYear = 1900;
    carPrice = 0.0;
    carMiles = 0;
}

/*Overloaded constructor with full parameters*/
Vehicle::Vehicle(string make, string model, unsigned int year, double price, unsigned int miles)
{
    carMake = make;
    carModel = model;
    carYear = year;
    carPrice = price;
    carMiles = miles;
}

/*Displays characteristics of vehicle*/
void Vehicle::Display()
{
    cout << carYear << " " << carMake << " " << carModel << " $" << carPrice << " " << carMiles << endl;
}

/*returns string of basic characteristics*/
string Vehicle::GetYearMakeModel()
{
    string YearMakeModel = to_string(carYear) + " " + carMake + " " + carModel;
    return YearMakeModel;
}

/*returns price of vehicle*/
float Vehicle::GetPrice()
{
    return carPrice;
}