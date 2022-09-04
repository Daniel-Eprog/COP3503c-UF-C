/*
COP3503c - Programming Fundamentals II - Lab 1
Data Visualization
Esteban Medero
September 4, 2022
This lab assignemnt is display an understanding of formatting output, receiving/formating input,
and error checking code. The lab takes in a title and two column headers. one for identification
and one for a numerical relation to the identifier. The program then outputs the data visually for
ease of reading.
*/


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    //Initialize variables for use in program
    string titleData;
    string col1Header;
    string col2Header;
    string dataEntry;
    int commaCount = 0;
    vector<string> dataString;
    vector<int> dataInteger;

    //Prompt and retrieve user input for title of data
    cout << "Enter a title for the data:" << endl;
    getline(cin, titleData);
    cout << "You entered: " << titleData << endl;

    //Prompt and retrieve user input for first column header
    cout << "Enter the column 1 header:" << endl;
    getline(cin, col1Header);
    cout << "You entered: " << col1Header << endl;

    //Prompt and retrieve user input for second column header
    cout << "Enter the column 2 header:" << endl;
    getline(cin, col2Header);
    cout << "You entered: " << col2Header << endl;

    //Prompts user for data points until user enters -1
    while (dataEntry != "-1")
    {
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataEntry);

        //Counts number of commas present, there should only be one
        for(size_t i = 0; i < dataEntry.size(); i++)
        {
            if(dataEntry.at(i) == ',')
            {
                commaCount += 1;
            }
        }
        //Checks for errors in the number of commas
        //restarts loop an initializes commaCount back to 0 if Error
        if(commaCount < 1 && dataEntry == "-1")
        {
            commaCount = 0;
            continue;
        }
        else if(commaCount < 1)
        {
            cout << "Error: No comma in string." << endl;
            commaCount = 0;
        }
        else if(commaCount > 1)
        {
            cout << "Error: Too many commas in input." << endl;
            commaCount = 0;
        }
        //If not comma errors checks for conversion exception on second input point. Must be convertible to int
        else
        {
            commaCount = 0;
            try
            {
                dataInteger.push_back(stoi(dataEntry.substr(dataEntry.find(',', 0) + 1, dataEntry.size() - 1)));
                dataString.push_back(dataEntry.substr(0, dataEntry.find(',', 0)));
                cout << "Data string: " << dataEntry.substr(0, dataEntry.find(',', 0)) << endl;
                cout << "Data integer: " << stoi(dataEntry.substr(dataEntry.find(',', 0) + 1, dataEntry.size() - 1)) << endl;
            }
            catch(exception)
            {
                cout << "Error: Comma not followed by an integer."<< '\n';
            }
            continue;
        }
    }

    //Formats header space
    cout << "\n";
    cout << setw(33) << right << titleData << endl;
    cout << setw(20) << left << col1Header << right << "|";
    cout << setw(23) << col2Header << endl;
    cout << setfill('-') << setw(44) << "" << endl;
    cout << setfill(' ');

    //Prints out first data chart
    for(size_t i = 0; i < dataString.size(); i++)
    {
        cout << setw(20) << left << dataString.at(i) << right << "|";
        cout << setw(23) << dataInteger.at(i) << endl;
    }

    cout << "\n";

    //Prints second data chart
    for(size_t i = 0; i < dataString.size(); i++)
    {
        cout << setw(20) << right << dataString.at(i) << " ";
        for(size_t j = 0; j < dataInteger.at(i); j++)
        {
            cout << "*";
        }
        cout << "\n";
    }



    return 0;
}