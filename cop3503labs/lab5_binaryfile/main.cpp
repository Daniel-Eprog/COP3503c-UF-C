/*
COP3503c - Programming Fundamentals II - Lab 5
Binary File I/O
Esteban Medero
October 23, 2022
This lab assignemnt is to display an understanding of reading binary files into a program. The
byte structure is provided and the file contains information about theoretical space ships.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Weapon
{
    string nameWeapon;
    int powerRate;
    float powerUse;
    Weapon(string name, int power, float consumption)
    {
            nameWeapon = name;
            powerRate = power;
            powerUse = consumption;
    }
};
struct Ship
{
    vector<Weapon> arsenal;
    string nameShip;
    string classType;
    short shipLength;
    int shieldCap;
    float speedWarp;
    int numWeapons;
    Ship(string name, string shipClass, short length, int shield, float warp, int weapons)
    {
        nameShip = name;
        classType = shipClass;
        shipLength = length;
        shieldCap = shield;
        speedWarp = warp;
        numWeapons = weapons;
    }

    void printInfo()
    {
        cout << "Name: " << this->nameShip << endl;
        cout << "Class: " << this->classType << endl;
        cout << "Length: " << this->shipLength << endl;
        cout << "Shield capacity: " << this->shieldCap << endl;
        cout << "Maximum Warp: " << this->speedWarp << endl;
        cout << "Armaments:" << endl;
        if(numWeapons == 0)
        {
            cout << "Unarmed\n" << endl;
        }
        else
        {
            int totalPower = 0;
            for(size_t i = 0; i < numWeapons; i++)
            {
                totalPower += arsenal.at(i).powerRate;
                cout << arsenal.at(i).nameWeapon << ", " << arsenal.at(i).powerRate << ", " << arsenal.at(i).powerUse << endl;
            }
            cout << "Total firepower: " << totalPower << endl << endl;
        }
    }
};
vector<Ship> readFile(string file);

int main()
{

    vector<Ship> availableShips;
    cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;
    
    if(option == 1)
    {
        availableShips = readFile("friendlyships.shp");

    }
    else if(option == 2)
    {
        availableShips = readFile("enemyships.shp");
    }
    else if(option == 3)
    {
        availableShips = readFile("friendlyships.shp");
        vector<Ship> enemyShips = readFile("enemyships.shp");
        availableShips.insert(availableShips.end(), enemyShips.begin(), enemyShips.end());
    }
   
    cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
	
	cin >> option;

    if(option == 1)
    {
        for(size_t i = 0; i < availableShips.size(); i++)
        {
            availableShips.at(i).printInfo();
        }
    }
    else if(option == 2)
    {
        int position = 0;
        int currentPower = 0;

        for(size_t i = 0; i < availableShips.size(); i++)
        {
            if(availableShips.at(i).numWeapons <= 0)
            {
                continue;
            }
            else
            {
                for(size_t j = 0; j < availableShips.at(i).arsenal.size(); j++)
                {
                    if(availableShips.at(i).arsenal.at(j).powerRate > currentPower)
                    {
                        currentPower = availableShips.at(i).arsenal.at(j).powerRate;
                        position = i;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

        availableShips.at(position).printInfo();
    }
    else if(option == 3)
    {
        int position = 0;
        int totalPower = 0;
        int currentPower = 0;

        for(size_t i = 0; i < availableShips.size(); i++)
        {
            if(availableShips.at(i).numWeapons <= 0)
            {
                continue;
            }
            else
            {
                for(size_t j = 0; j < availableShips.at(i).arsenal.size(); j++)
                {
                    totalPower += availableShips.at(i).arsenal.at(j).powerRate;
                }
                if(totalPower > currentPower)
                {
                    position = i;
                    currentPower = totalPower;
                    totalPower = 0;
                }
                else
                {
                    totalPower = 0;
                    continue;
                }
            }
        }

        availableShips.at(position).printInfo();

    }
    else if(option == 4)
    {
        int position = 0;
        int totalPower = 0;
        int currentPower = 0;

        for(size_t i = 0; i < availableShips.size(); i++)
        {
            if(availableShips.at(i).numWeapons <= 0)
            {
                continue;
            }
            else
            {
                for(size_t j = 0; j < availableShips.at(i).arsenal.size(); j++)
                {
                    totalPower += availableShips.at(i).arsenal.at(j).powerRate;
                }
                if(currentPower == 0)
                {
                    position = i;
                    currentPower = totalPower;
                    totalPower = 0;
                }
                else if(totalPower < currentPower)
                {
                    position = i;
                    currentPower = totalPower;
                    totalPower = 0;
                }
                else
                {
                    totalPower = 0;
                    continue;
                }
            }
        }

        availableShips.at(position).printInfo();

    }
    else if(option == 5)
    {
        for(size_t i = 0; i < availableShips.size(); i++)
        {
            if(availableShips.at(i).numWeapons <= 0)
            {
                availableShips.at(i).printInfo();
            }
            else
            {
                continue;
            }
        }
    }

    return 0;

}

vector<Ship> readFile(string file)
{
    /*Counter variables*/
    int numShips;
    int numWeapons;
    int lengthData;

    /*Ship variables*/
    string shipName;
    string shipClass;
    short shipLength;
    int shieldCapacity;
    float warpSpeed;

    /*Weapon Variables*/
    string weaponName;
    int powerRating;
    float powerConsumption;

    /*Vector of available ships*/
    vector<Ship> availableShips;
    /*Opens desired file*/
    ifstream fileToOpen(file, ios_base::binary);

    /*Checks if file was succesfully opened*/
    if(!fileToOpen.is_open())
    {
        cout << "Sorry, could not open file." << endl;
    }
    else
    {
        fileToOpen.read(reinterpret_cast<char*>(&numShips), sizeof(numShips));
        for(short i = 0; i < numShips; i++)
        {
            fileToOpen.read(reinterpret_cast<char*>(&lengthData), sizeof(lengthData)); //Read in length of ship name
            char *data = new char[lengthData]; //Allocates space for character array of  appropriate length  
            fileToOpen.read(reinterpret_cast<char*>(data), lengthData * sizeof(data[0]));//Reads in the name of the ship
            shipName = data;//Copys name of ship into a c++ string
            delete[] data;//Deallocates space saved for ship name
            fileToOpen.read(reinterpret_cast<char*>(&lengthData), sizeof(lengthData));
            data = new char[lengthData];
            fileToOpen.read(reinterpret_cast<char*>(data), lengthData * sizeof(data[0]));
            shipClass = data;
            delete[] data;
            fileToOpen.read(reinterpret_cast<char*>(&shipLength), sizeof(shipLength));
            fileToOpen.read(reinterpret_cast<char*>(&shieldCapacity), sizeof(shieldCapacity));
            fileToOpen.read(reinterpret_cast<char*>(&warpSpeed), sizeof(warpSpeed));
            fileToOpen.read(reinterpret_cast<char*>(&numWeapons), sizeof(numWeapons));
            if(numWeapons == 0)
            {
                // cout << "unarmed " << shipName << endl;
                // Ship * tempShip = new Ship(shipName, shipClass, shipLength, shieldCapacity, warpSpeed, numWeapons);
                availableShips.push_back(Ship(shipName, shipClass, shipLength, shieldCapacity, warpSpeed, numWeapons));
                // delete tempShip;
            }
            else
            {
                availableShips.push_back(Ship(shipName, shipClass, shipLength, shieldCapacity, warpSpeed, numWeapons));
                for(short j = 0; j < numWeapons; j++)
                {
                    fileToOpen.read(reinterpret_cast<char*>(&lengthData), sizeof(lengthData));
                    data = new char[lengthData];
                    fileToOpen.read(reinterpret_cast<char*>(data), lengthData * sizeof(data[0]));
                    weaponName = data;
                    delete[] data;
                    fileToOpen.read(reinterpret_cast<char*>(&powerRating), sizeof(powerRating));
                    fileToOpen.read(reinterpret_cast<char*>(&powerConsumption), sizeof(powerConsumption));
                    availableShips.at(i).arsenal.push_back(Weapon(weaponName, powerRating, powerConsumption));
                }
            }
        
        }

    }

    return availableShips;

}