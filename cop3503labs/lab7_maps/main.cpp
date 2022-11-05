#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

mt19937 random_mt;

struct State
{
    int incomePerCapita = 0;
    int population = 0;
    int houseIncome = 0;
    int numHouses = 0;
    State(int capIncome, int pop, int homeIncome, int numberHouses)
    : incomePerCapita{capIncome}, population{pop}, houseIncome{homeIncome}, numHouses{numberHouses} { }

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

        for(size_t i = 1; i <= numberSides; i++)
        {
            diceRoll.emplace(i, 0);
        }

        int currentRoll = 0;

        for(size_t i = 0; i < numberRolls; i++)
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

    State florida = State(1, 2, 3, 4);
    cout << florida.population << endl;

    string stateName;
    int cap;
    int pop;
    int home;
    int house;
    map<string, State> stateStats;
    ifstream fileToOpen;

    fileToOpen.open("statedata.csv");
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

                stateStats.emplace(stateName, State(stoi(cap), stoi(pop), stoi(home), stoi(house)));
              
            }

      

	   // Load the states
	   
	   // Get input for option 1 (show all states) or 2 (do a search for a particular state)

     }
    }

	return 0;
}
