//
//  
//
//  Description: Software Sales
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // declare variables
    int numberOfUnitsSold;
    const int packagePrice = 99;
    double discountRaw;
    double discountPercent;
    double discountAmount;
    double regularPrice;
    double netPrice;
    
    // ask user for number of units sold
        cout<< "How many units sold?" << endl;
        cin>> numberOfUnitsSold;
    
    // if statements to determine what discount the customer recieves
        if ( numberOfUnitsSold < 10 )
        {
            discountRaw = 0;
            discountPercent = discountRaw / 100;
            regularPrice = numberOfUnitsSold * packagePrice;
            discountAmount = regularPrice * discountPercent;
            netPrice = regularPrice - discountAmount;
        }
        else if ( numberOfUnitsSold >= 10 && numberOfUnitsSold < 20 )
        {
            discountRaw = 20;
            discountPercent = discountRaw / 100;
            regularPrice = numberOfUnitsSold * packagePrice;
            discountAmount = regularPrice * discountPercent;
            netPrice = regularPrice - discountAmount;
        }
        else if ( numberOfUnitsSold >= 20 && numberOfUnitsSold < 50 )
        {
            discountRaw = 30;
            discountPercent = discountRaw / 100;
            regularPrice = numberOfUnitsSold * packagePrice;
            discountAmount = regularPrice * discountPercent;
            netPrice = regularPrice - discountAmount;
        }
        else if ( numberOfUnitsSold >= 50 && numberOfUnitsSold < 100 )
        {
            discountRaw = 40;
            discountPercent = discountRaw / 100;
            regularPrice = numberOfUnitsSold * packagePrice;
            discountAmount = regularPrice * discountPercent;
            netPrice = regularPrice - discountAmount;
        }
        else if ( numberOfUnitsSold >= 100)
        {
            discountRaw = 50;
            discountPercent = discountRaw / 100;
            regularPrice = numberOfUnitsSold * packagePrice;
            discountAmount = regularPrice * discountPercent;
            netPrice = regularPrice - discountAmount;
        }
        else
        {
            discountRaw = 0;
            discountPercent = discountRaw / 100;
            regularPrice = numberOfUnitsSold * packagePrice;
            discountAmount = regularPrice * discountPercent;
            netPrice = regularPrice - discountAmount;
        }
                
    // output
        cout<< "Software Sales:" << endl;
        cout<< "Regular Price of " << numberOfUnitsSold << ":   " << setprecision(2) << fixed << setw(8) << right << regularPrice << endl;
        cout<< "Discounted " << setprecision(0) << fixed << setw(2)<< discountRaw << "%:         " << setprecision(2) << fixed << setw(7) << right << discountAmount << endl;
        cout<< "Net Price:             " << setprecision(2) << fixed << setw(8) << right << netPrice << endl;
    
    cout<< endl;
    return 0;
}
