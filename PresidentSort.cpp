//
//  Description: President Sort
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void loadArray(string[], int, int&);
void printArray(string[], int);
void sortArray(string[], int);

int main()
{
    int SIZE = 50;
    int count;
    string presidentNames[SIZE];
    loadArray(presidentNames, SIZE, count);
    cout<< endl;
    SIZE = count;
    printArray(presidentNames, SIZE);
    sortArray(presidentNames, SIZE);
    printArray(presidentNames, SIZE);
    
    cout<< endl;
    return 0;
}

void loadArray(string presidentNames[], int SIZE, int& count)
{
    ifstream inputFile;
    string fileName;
    count = 0;
    cout<< "Enter the file path: " << endl;                                     // /Users/warrenwright/Desktop/Presidents.txt
    getline(cin,fileName);
    inputFile.open(fileName);
    
    while(!inputFile)
    {
        cout<< "File not found." << endl;
        cout<< "Enter the file path: " << endl;
        getline(cin,fileName);
        inputFile.open(fileName);
    }
    
    getline(inputFile, presidentNames[count]);
    while(!inputFile.eof())
    {
        count++;
        getline(inputFile, presidentNames[count]);
    }
    count++;
    getline(inputFile, presidentNames[count]);
    inputFile.close();
}

void printArray(string presidentNames[], int SIZE)
{
    int x;
    for(x=0; x<=SIZE; x++)
    {
        cout<< presidentNames[x] << endl;
    }
}

void sortArray(string presidentNames[], int SIZE)
{
    int x;
    int y;
    string temp;
    
    for(x=0; x<=SIZE; x++)
    {
        for(y=x+1; y<= SIZE; y++)
        {
            if(presidentNames[x] > presidentNames[y])
            {
                temp = presidentNames[x];
                presidentNames[x] = presidentNames[y];
                presidentNames[y] = temp;
            }
        }
    }
}
