//
//  Description: Password Verifier
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

string askForPassword(string&);
bool verifyLength(string&);
bool verifyUpperCase(string&);
bool verifyLowerCase(string&);
bool verifyDigit(string&);
bool verifyNoSpace(string&);
bool verifySpecial(string&);

int main()
{
    string password;
    password = askForPassword(password);
    bool acceptablePassword = false;
    
    while (acceptablePassword !=true)
    {
        verifyLength(password);
        verifyUpperCase(password);
        verifyLowerCase(password);
        verifyDigit(password);
        verifySpecial(password);
        verifyNoSpace(password);
        if((verifyLength(password) == true) && (verifyUpperCase(password) == true) && (verifyLowerCase(password) == true) && (verifyDigit(password) == true) && (verifyNoSpace(password) == false) && (verifySpecial(password) == true))
        {
            acceptablePassword = true;
        }
    }
    
    cout<< "Password confirmed." << endl;
    cout<< endl;
    return 0;
}

string askForPassword(string & password)
{
    cout<< "Please create a password: " << endl;
    getline(cin, password);
    cout<< endl;
    return password;
}

bool verifyLength(string & password)
{
    bool acceptableLength;
    int length = password.length();
    
    if(length < 12)
    {
        acceptableLength = false;
        cout<< "Password must be atleast 12 characters long." << endl;
        cout<< "Please create a password: " << endl;
        getline(cin,password);
        cout<< endl;
    }
    else
    {
        acceptableLength = true;
    }
    return acceptableLength;
}

bool verifyUpperCase(string & password)
{
    bool containsUpperCase = false;
    int x;
    for(x=0; x<=password.length() - 1; x++)
    {
        if(isupper(password[x]))
        {
            containsUpperCase = true;
        }
    }
    if(containsUpperCase == false)
    {
        cout<< "Password must contain atleast 1 Uppercase character." << endl;
        cout<< "Please create a password: " << endl;
        getline(cin,password);
        cout<< endl;
    }
    return containsUpperCase;
}
bool verifyLowerCase(string & password)
{
    bool containsLowerCase = false;
    int x;
    for(x=0; x<=password.length()-1; x++)
    {
        if(islower(password[x]))
        {
            containsLowerCase = true;
        }
    }
    if(containsLowerCase == false)
    {
        cout<< "Password must contain atleast 1 Lowercase character." << endl;
        cout<< "Please create a password: " << endl;
        getline(cin,password);
        cout<< endl;
    }
    return containsLowerCase;
}
bool verifyDigit(string & password)
{
    bool containsDigit = false;
    int x;
    for(x=0; x<=password.length()-1; x++)
    {
        if(isdigit(password[x]))
        {
            containsDigit = true;
        }
    }
    if(containsDigit == false)
    {
        cout<< "Password must contain atleast 1 Digit." << endl;
        cout<< "Please create a password: " << endl;
        getline(cin,password);
        cout<< endl;
    }
    return containsDigit;
}

bool verifyNoSpace(string & password)
{
    bool containsSpace = false;
    int x;
    for(x=0; x<=password.length()-1; x++)
    {
        if(isspace(password[x]))
        {
            containsSpace = true;
        }
    }
    if(containsSpace == true)
    {
        cout<< "Password cannot have any spaces." << endl;
        cout<< "Please create a password: " << endl;
        getline(cin,password);
        cout<< endl;
    }
    return containsSpace;
}

bool verifySpecial(string & password)
{
    bool containsSpecial = false;
    int x;
    for(x=0; x<=password.length()-1; x++)
    {
        if(ispunct(password[x]))
        {
            containsSpecial = true;
        }
    }
    if(containsSpecial == false)
    {
        cout<< "Password must contain atleast 1 Special character." << endl;
        cout<< "Please create a password: " << endl;
        getline(cin,password);
        cout<< endl;
    }
    return containsSpecial;
}
