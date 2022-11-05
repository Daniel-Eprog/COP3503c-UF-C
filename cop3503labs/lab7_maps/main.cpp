#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

mt19937 random_mt;

struct State
{
    string incomePerCapita;
    string population;
    string houseIncome;
    string numHouses;
    State(string capIncome, string pop, string homeIncome, string numberHouses)
    : incomePerCapita{capIncome}, population{pop}, houseIncome{homeIncome}, numHouses{numberHouses} { }
    void Print() 
    {
        cout << "Population: " << this->population << endl;
        cout << "Per Capita Income: " << this->incomePerCapita << endl;
        cout << "Median Household Income: " << this->houseIncome << endl;
        cout << "Number of Households: " << this->numHouses << endl;
    }

};

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
        int numberRolls;
        int numberSides;
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		cout << "Number of times to roll the die: ";
        cin >> numberRolls;

		cout << "Number of sides on this die: ";
        cin >> numberSides;

        map<int, int> diceRoll;

        for(int i = 1; i <= numberSides; i++)
        {
            diceRoll.emplace(i, 0);
        }

        int currentRoll = 0;

        for(int i = 0; i < numberRolls; i++)
        {
            
            currentRoll = Random(1, numberSides);
            for(auto &dicePair : diceRoll)
            {
                if(dicePair.first == currentRoll)
                {
                    dicePair.second += 1;
                }
                else
                {
                    continue;
                }
            }
        }

        for(auto &dicePair : diceRoll)
        {
            cout << dicePair.first << ": " << dicePair.second << endl;
        }


	}
	else if (option == 2)
	{

    string stateName;
    string cap;
    string pop;
    string home;
    string house;
    map<string, State> stateStats;
    ifstream fileToOpen;

    fileToOpen.open("states.csv");
    if(!fileToOpen.is_open())
    {
        cout << "sorry file could not be opened" << endl;
    }
    else
    {

        string discard;
        getline(fileToOpen, discard);
        while(!fileToOpen.eof())
        {

            getline(fileToOpen, stateName, ',');
            getline(fileToOpen, cap, ',');
            getline(fileToOpen, pop, ',');
            getline(fileToOpen, home, ',');
            getline(fileToOpen, house);

            stateStats.emplace(stateName, State(cap, pop, home, house));
              
        }
        
        cout << "1. Print all states" << endl;
        cout << "2. Search for a state" << endl;
        cin >> option;

        if(option == 1)
        {
            map<string, State>::iterator iter;
            for(auto iter = stateStats.begin(); iter != stateStats.end(); iter++)
            {   
                if(iter == stateStats.begin())
                {
                    continue;
                }
                else
                {
                cout << iter->first << endl;
                iter->second.Print();
                }
            }
        }
        else if(option == 2)
        {
            string searchState;
            getline(cin, searchState);//take in user input
            
            map<string, State>::iterator iter;
            iter = stateStats.find(searchState);

            if(iter != stateStats.end())
            {
                cout << searchState << endl;
                iter->second.Print();
            }
            else
            {
                cout << "No match found for " << searchState << endl;
            }
        }
     }
    }

	return 0;
}
