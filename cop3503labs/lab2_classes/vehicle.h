/*Header file for Vehicle class*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

/*class declaration*/
class Vehicle
{
    /*privately accessible class members*/
    private:
    
        string carMake;
        string carModel;
        unsigned int carYear;
        double carPrice = 0.0;
        unsigned int carMiles;

    /*publicly accessible member functions*/
    public:

        Vehicle();
        Vehicle(string carMake, string carModel, unsigned int carYear, double carPrice, unsigned int carMiles);
        void Display();
        string GetYearMakeModel();
        float GetPrice();
};

#endif