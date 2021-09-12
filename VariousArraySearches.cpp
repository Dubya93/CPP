//
//  Description: Search Benchmarks
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void randomizeArray(int [], int);
void displayArray(int [], int);
void sortArray(int [], int);
void sequentialSearch(int [], int);
void binarySearch(int [], int);

int main()
{
    const int SIZE = 100;
    int randomNumber[SIZE];
    
    
    randomizeArray(randomNumber, SIZE);
    displayArray(randomNumber, SIZE);
    sequentialSearch(randomNumber, SIZE);
    sortArray(randomNumber, SIZE);
    cout<< endl;
    displayArray(randomNumber, SIZE);
    cout<< endl;
    binarySearch(randomNumber, SIZE);
    cout<< endl;
    
    return 0;
}

void randomizeArray(int randomNumber[], int SIZE)
{
    unsigned seed = time(0);
    srand(seed);
    int x;
    
    for(x=0; x<=SIZE; x++)
    {
        randomNumber[x] = (rand() % 501)+500;
    }
}

void displayArray(int randomNumber[], int SIZE)
{
    int x;
    int y;
    int z;
    for(x=0; x<=(SIZE); x++)
    {
        for(y=0; y<=9; y++)
        {
            for(z=0; z<=9; z++)
            {
                cout<< randomNumber[x] << " ";
                x++;
            }
            cout<< endl;
        }
        cout<< endl;
    }
}

void sortArray(int randomNumber[], int SIZE)
{
    int x;
    int y;
    int temp;
    
    for(x=0; x<=SIZE-1; x++)
    {
        for(y=x+1; y<= SIZE; y++)
        {
            if (randomNumber[x] > randomNumber[y])
            {
                temp = randomNumber[x];
                randomNumber[x] = randomNumber[y];
                randomNumber[y] = temp;
            }
        }
    }
}

void sequentialSearch(int randomNumber[], int SIZE)
{
    int x;
    int key;
    int spot = 0;
    
    cout<< "What number would you like to search for?: ";
    cin>> key;
    
    for(x=0; x<=SIZE; x++)
    {
        if (randomNumber[x] == key)
        {
            spot = x;
            cout<< endl << "Found it!" << endl;
            cout<< "It took " << spot << " searches." << endl;
        }
        else if (randomNumber[x] < key)
        {
            spot++;
        }
        else if(randomNumber[x] > key)
        {
            spot++;
        }
    }
    spot--;
    if(spot>=SIZE)
    {
        cout<< "The number could not be found in " << spot << " searches." << endl;
    }
}

void binarySearch(int randomNumber[], int SIZE)
{
    int max = SIZE;
    int min = 0;
    int x;
    int key;
    int spot = 0;
    
    cout<< "What number would you like to search for?: ";
    cin>> key;
    
    while(min <= max)
    {
        min = min;
        max = max;
        x = (max + min)/2;
        
        if(randomNumber[x] == key)
        {
            cout<< endl << "Found it!" << endl;
            cout<< "It took " << spot << " searches." << endl;
            min = max + 1;
        }
        
        else if(randomNumber[x] < key)
        {
            spot++;
            min = x + 1;
            max = max;
        }
        else if(randomNumber[x] > key)
        {
            spot++;
            max = x - 1;
            min = min;
        }
    }
    if(spot>=7)
    {
        cout<< "The number could not be found " << spot << " searches." << endl;
    }
}
