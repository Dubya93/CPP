//
//  Warren Wright
//  CS1143 Section 5
//  Description: String Reverse
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

string askString(string);
string reverseString(string);
void printString(string, string);

int main()
{
    string wordORphrase;
    string reverse_wordORphrase;
    
    wordORphrase = askString(wordORphrase);
    cout<< endl;
    reverse_wordORphrase = reverseString(wordORphrase);
    printString(wordORphrase, reverse_wordORphrase);
    
    cout<< endl;
    return 0;
}

string askString(string wordORphrase)
{
    cout<< "What word or phrase would you like to reverse?: " << endl;
    getline(cin,wordORphrase);
    return wordORphrase;
}

string reverseString(string wordORphrase)
{
    int length = wordORphrase.length();
    int x = length - 1;
    int y;
    
    for(y=0; y<(length/2); y++)
    {
        char temp = wordORphrase[y];
        wordORphrase[y] = wordORphrase[x];
        wordORphrase[x] = temp;
        x = x - 1;
    }
    return wordORphrase;
}

void printString(string wordORphrase, string reverse_wordORphrase)
{
    cout<< "The reverse of '" << wordORphrase << "' is '" << reverse_wordORphrase << "'" << endl;
}
