//
//
//
//  Description: Prime Number Program
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int isPrime(int &, int &);

int main()
{
    ofstream outputFile;
    string fileName;                //  /Users/warrenwright/Desktop/PrimeNumberOutPut.txt
    
    int beginningNumber;
    int endingNumber;
    int checkNumber;
    int primeNumber;
    int numberSwap;
    int x;
    
    
    
    cout<< "What is the beginning number in the range?: ";
    cin>> beginningNumber;
    cout<< endl;
    cout<< "What is the ending number in the range?: ";
    cin>> endingNumber;
    cout<< endl;
    
    cin.ignore();
    cout<< "Enter the file name for report output?: " << endl;
    getline(cin,fileName);
    outputFile.open(fileName);
    
    while (!outputFile)
    {
        cout<< "File not found." << endl;
        cout<< "Please enter file name for report output: " << endl;
        getline(cin,fileName);
        outputFile.open(fileName);
    }
    
    outputFile << "These are the Prime Numbers between " << beginningNumber << " and " << endingNumber << "." << endl;
    
    if (beginningNumber > endingNumber)
    {
        numberSwap = beginningNumber;
        beginningNumber = endingNumber;
        endingNumber = numberSwap;
    }
    else if (beginningNumber == endingNumber)
    {
        cout<< "This is not a range. Please enter beginning number: ";
        cin>> beginningNumber;
        cout<< "Please enter ending number: ";
        cin>> endingNumber;
        cout<< endl;
    }
    else
    {
        beginningNumber = beginningNumber;
        endingNumber = endingNumber;
    }
    
    for (checkNumber = beginningNumber; checkNumber <= endingNumber; checkNumber++)
    {
        isPrime(checkNumber, x);
        if (x == 1)
        {
            primeNumber = checkNumber;
            outputFile<< primeNumber << endl;
        }
    }
    
    outputFile.close();
    cout<< endl;
    return 0;
}

int isPrime(int & checkNumber, int & x)
{
    if ((checkNumber <=3))
    {
        x = 1;
    }
    else if ((checkNumber % 2 != 0) && (checkNumber % 3 != 0) && (checkNumber <= 5))
    {
        x = 1;
    }
    else if ((checkNumber % 2 != 0) && (checkNumber % 3 != 0) && (checkNumber % 5 != 0) && (checkNumber <= 7))
    {
        x = 1;
    }
    else if ((checkNumber % 2 != 0) && (checkNumber % 3 != 0) && (checkNumber % 5 != 0) && (checkNumber % 7 != 0) && (checkNumber > 8))
    {
        x = 1;
    }
    else
    {
        x = 0;
    }
    return x;
}
