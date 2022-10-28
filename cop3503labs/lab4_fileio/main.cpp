#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<string> setNumber;
    vector<string> setTheme;
    vector<string> setName;
    vector<int> setMinis;
    vector<int> numPieces;
    vector<double> setPrice;

	cout << std::fixed << setprecision(2);
	// cout << "Which file(s) to open?\n";
	// cout << "1. lego1.csv" << endl;
	// cout << "2. lego2.csv" << endl;
	// cout << "3. lego3.csv" << endl;
	// cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

   string newbuffer;
   ifstream fileToOpen;

   if(option == 1)
   {
    fileToOpen.open("lego1.csv");
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
                getline(fileToOpen, newbuffer, ',');
                setNumber.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setTheme.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setName.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setMinis.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer, ',');
                numPieces.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer);
                setPrice.push_back(stod(newbuffer));
            }

            fileToOpen.close();

        }
   }
   else if (option == 2)
   {
        fileToOpen.open("lego2.csv");
        if(!fileToOpen.is_open())
        {
                cout << "sorry file could not be opened" << endl;
        }
        else
        {
        /*Discards the first line of the file which is the titles of each column*/
        string discard;
        getline(fileToOpen, discard);

            /*Iterates over whole file placing respective item in vector*/
            while(!fileToOpen.eof())
            {
                getline(fileToOpen, newbuffer, ',');
                setNumber.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setTheme.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setName.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setMinis.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer, ',');
                numPieces.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer);
                setPrice.push_back(stod(newbuffer));
            }
            
            /*Closes file after copying contents*/
            fileToOpen.close();
        }
   }
   else if(option == 3)
   {
        fileToOpen.open("lego3.csv");
        if(!fileToOpen.is_open())
        {
                cout << "sorry file could not be opened" << endl;
        }
        else
        {
        /*Discards the first line of the file which is the titles of each column*/
        string discard;
        getline(fileToOpen, discard);

            /*Iterates over whole file placing respective item in vector*/
            while(!fileToOpen.eof())
            {
                getline(fileToOpen, newbuffer, ',');
                setNumber.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setTheme.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setName.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setMinis.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer, ',');
                numPieces.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer);
                setPrice.push_back(stod(newbuffer));
            }
            
            /*Closes file after copying contents*/
            fileToOpen.close();
        }
   }
   else if (option == 4)
   {
        fileToOpen.open("lego1.csv");
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
                getline(fileToOpen, newbuffer, ',');
                setNumber.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setTheme.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setName.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setMinis.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer, ',');
                numPieces.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer);
                setPrice.push_back(stod(newbuffer));
            }

            fileToOpen.close();

        }
        fileToOpen.open("lego2.csv");
        if(!fileToOpen.is_open())
        {
                cout << "sorry file could not be opened" << endl;
        }
        else
        {
        /*Discards the first line of the file which is the titles of each column*/
        string discard;
        getline(fileToOpen, discard);

            /*Iterates over whole file placing respective item in vector*/
            while(!fileToOpen.eof())
            {
                getline(fileToOpen, newbuffer, ',');
                setNumber.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setTheme.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setName.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setMinis.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer, ',');
                numPieces.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer);
                setPrice.push_back(stod(newbuffer));
            }
            
            /*Closes file after copying contents*/
            fileToOpen.close();
        }
        fileToOpen.open("lego3.csv");
        if(!fileToOpen.is_open())
        {
                cout << "sorry file could not be opened" << endl;
        }
        else
        {
        /*Discards the first line of the file which is the titles of each column*/
        string discard;
        getline(fileToOpen, discard);

            /*Iterates over whole file placing respective item in vector*/
            while(!fileToOpen.eof())
            {
                getline(fileToOpen, newbuffer, ',');
                setNumber.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setTheme.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setName.push_back(newbuffer);
                getline(fileToOpen, newbuffer, ',');
                setMinis.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer, ',');
                numPieces.push_back(stoi(newbuffer));
                getline(fileToOpen, newbuffer);
                setPrice.push_back(stod(newbuffer));
            }
            
            /*Closes file after copying contents*/
            fileToOpen.close();
        }

    
   }
 
    // cout << "1. Most Expensive set" << endl;
	// cout << "2. Largest piece count" << endl;
	// cout << "3. Search for set name containing..." << endl;
	// cout << "4. Search themes..." << endl;
	// cout << "5. Part count information" << endl;
	// cout << "6. Price information" << endl;
	// cout << "7. Minifigure information" << endl;
	// cout << "8. If you bought one of everything..." << endl;
	// cout << "0. Exit" << endl;
   
	int choice;
	cin >> choice;
    cin.get();  // Clear newline character for any later input
   
   cout << "Total number of sets: " << setName.size() << endl << endl;
   if(choice == 1)
   {
        int positionCounter = 0;
        for( size_t i = 1; i < setPrice.size(); i++)
        {
            if(setPrice.at(i) > setPrice.at(positionCounter))
            {
                positionCounter = i;
            }
        }

        cout << "The most expensive set is:" << endl;
        cout << "Name: " << setName.at(positionCounter) << endl;
        cout << "Number: " << setNumber.at(positionCounter) << endl;
        cout << "Theme: " << setTheme.at(positionCounter) << endl;
        cout << "Price: $" << setPrice.at(positionCounter) << endl;
        cout << "Minifigures: " << setMinis.at(positionCounter) << endl;
        cout << "Piece count: " << numPieces.at(positionCounter) << endl;
   }
   else if(choice == 2)
   {
        int positionCounter = 0;
        for( size_t i = 1; i < numPieces.size(); i++)
        {
            if(numPieces.at(i) > numPieces.at(positionCounter))
            {
                positionCounter = i;
            }
        }

        cout << "The set with the highest parts count:" << endl;
        cout << "Name: " << setName.at(positionCounter) << endl;
        cout << "Number: " << setNumber.at(positionCounter) << endl;
        cout << "Theme: " << setTheme.at(positionCounter) << endl;
        cout << "Price: $" << setPrice.at(positionCounter) << endl;
        cout << "Minifigures: " << setMinis.at(positionCounter) << endl;
        cout << "Piece count: " << numPieces.at(positionCounter) << endl;
   }
   else if(choice == 3)
   {
     string searchTerm;
     getline(cin, searchTerm);
     vector<int> foundPosition;

     for(size_t i = 0; i < setName.size(); i++)
     {
        if(setName.at(i).find(searchTerm) != string::npos)
        {
            foundPosition.push_back(i);
        }
     }

     if(foundPosition.size() <= 0)
     {
        cout << "No sets found matching that search term" << endl;
     }
     else
     {
        cout << "Sets matching \"" << searchTerm << "\":" << endl;
        for(size_t i = 0; i<foundPosition.size(); i++)
        {
            cout << setNumber.at(foundPosition.at(i)) << " ";
            cout << setName.at(foundPosition.at(i)) << " ";
            cout << "$" << setPrice.at(foundPosition.at(i)) << endl;

        }
     }

   }
   else if(choice == 4) 
   {
     string searchTerm;
     getline(cin, searchTerm);
     vector<int> foundPosition;
     
     for(size_t i = 0; i < setTheme.size(); i++)
     {
        if(setTheme.at(i).find(searchTerm) != string::npos)
        {
            foundPosition.push_back(i);
        }
     }

     if(foundPosition.size() <= 0)
     {
        cout << "No sets found matching that search term" << endl;
     }
     else
     {
        cout << "Sets matching \"" << searchTerm << "\":" << endl;
        for(size_t i = 0; i<foundPosition.size(); i++)
        {
            cout << setNumber.at(foundPosition.at(i)) << " ";
            cout << setName.at(foundPosition.at(i)) << " ";
            cout << "$" << setPrice.at(foundPosition.at(i)) << endl;

        }
     }

   }
   else if(choice == 5)
   {
    int totalParts = 0;
    for(size_t i = 0; i < numPieces.size(); i++)
    {
        totalParts += numPieces.at(i);
    }

    cout << "Average part count for " << numPieces.size() << " sets: " << totalParts/numPieces.size() << endl;

   }
   else if(choice == 6)
   {

    double totalPrice = 0;
    int minPos = 0;
    int maxPos = 0;
    for(size_t i = 0; i < setPrice.size(); i++)
    {
        totalPrice += setPrice.at(i);
        if(setPrice.at(i) < setPrice.at(minPos))
        {
            minPos = i;
        }
        if(setPrice.at(i) > setPrice.at(maxPos))
        {
            maxPos = i;
        }
    }

    cout << "Average price for " << setPrice.size() << " sets: $" << totalPrice/setPrice.size() << endl << endl;
    cout << "Least expensive set:" << endl;
    cout << "Name: " << setName.at(minPos) << endl;
    cout << "Number: " << setNumber.at(minPos) << endl;
    cout << "Theme: " << setTheme.at(minPos) << endl;
    cout << "Price: $" << setPrice.at(minPos) << endl;
    cout << "Minifigures: " << setMinis.at(minPos) << endl;
    cout << "Piece count: " << numPieces.at(minPos) << endl << endl;
    cout << "Most expensive set:" << endl;
    cout << "Name: " << setName.at(maxPos) << endl;
    cout << "Number: " << setNumber.at(maxPos) << endl;
    cout << "Theme: " << setTheme.at(maxPos) << endl;
    cout << "Price: $" << setPrice.at(maxPos) << endl;
    cout << "Minifigures: " << setMinis.at(maxPos) << endl;
    cout << "Piece count: " << numPieces.at(maxPos) << endl;

   }
   else if(choice == 7)
   {
    int totalFigs = 0;
    int maxPos = 0;
    for(size_t i = 0; i < setMinis.size(); i++)
    {
        totalFigs += setMinis.at(i);
        if(setMinis.at(i) > setMinis.at(maxPos))
        {
            maxPos = i;
        }
    }

    cout << "Average number of minifigures:  " << totalFigs/setMinis.size() << endl;
    cout << "Set with the most minifigures: " << endl;
    cout << "Name: " << setName.at(maxPos) << endl;
    cout << "Number: " << setNumber.at(maxPos) << endl;
    cout << "Theme: " << setTheme.at(maxPos) << endl;
    cout << "Price: $" << setPrice.at(maxPos) << endl;
    cout << "Minifigures: " << setMinis.at(maxPos) << endl;
    cout << "Piece count: " << numPieces.at(maxPos) << endl;

   }
   else if(choice == 8)
   {
    double totalPrice = 0;
    int totalPieces = 0;
    int totalMinis = 0;

     for(size_t i = 0; i < setMinis.size(); i++)
     {
        totalMinis += setMinis.at(i);
        totalPrice += setPrice.at(i);
        totalPieces += numPieces.at(i);

     }

     cout << "If you bought one of everything..." << endl;
     cout << "It would cost: $" << totalPrice << endl;
     cout << "You would have " << totalPieces << " pieces in your collection" << endl;
     cout << "You would have an army of " << totalMinis << " minifigures!" << endl;
   }
   else if(choice == 0)
   {
      return 0;
   }



	return 0;
}


