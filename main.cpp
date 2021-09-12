//  Warren Wright
//  CS 1143 Section 5
//  Description: Lowest Score Drop

#include <iostream>
#include <iomanip>
using namespace std;

void getScore(double &);
void calcAverage(double, double, double, double, double, double);
double findLowest(double, double, double, double, double, double);

int main()
{
    static double score1;
    static double score2;
    static double score3;
    static double score4;
    static double score5;
    static double score6;

    
    getScore(score1);
    getScore(score2);
    getScore(score3);
    getScore(score4);
    getScore(score5);
    getScore(score6);
    
    
    cout<< endl;
    cout<< "The Test scores are " << score1 << " " << score2 << " " << score3 << " " << score4 << " " << score5 << " " << score6 << endl;
    calcAverage(score1, score2, score3, score4, score5, score6);
    cout<< endl;
    return 0;
}

void getScore(double & score)
{
    double testScore;
    static int testNumber = 1;
    cout << "Enter the score of test number " << testNumber << ": ";
    cin >> testScore;
    testNumber++;
    while ((testScore < 0) || (testScore > 100))
    {
        cout<< "Test scores values can only be between 0 and 100." << endl;
        cout<< "Please reenter the test score: ";
        cin>> testScore;
    }
    score = testScore;
}

double findLowest(double score1, double score2, double score3, double score4, double score5, double score6)
{
    double lowestScore;
    if (score1 <= score2)
    {
        lowestScore = score1;
    }
    else
    {
        lowestScore = score2;
    }
    if (score3 < lowestScore)
    {
        lowestScore = score3;
    }
    if (score4 < lowestScore)
    {
        lowestScore = score4;
    }
    if (score5 < lowestScore)
    {
        lowestScore = score5;
    }
    if (score6 < lowestScore)
    {
        lowestScore = score6;
    }
    cout<< endl;
    cout<< "The lowest test score is: " << lowestScore << endl;
    return lowestScore;
}

void calcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
{
    double numberOfTests = 5;
    double dropScore = findLowest(score1, score2, score3, score4, score5, score6);
    double average = (score1 + score2 + score3 + score4 + score5 + score6 - dropScore)/ numberOfTests;
    cout<< endl;
    cout<< "The average score of your tests is: " << setprecision(2) << fixed << average << endl;
}
