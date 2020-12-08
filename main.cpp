//
//  
//
//  Description: Star Search Array Version

#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(double &);
double lowestScore(double[], int);
double highestScore(double[], int);
void calcAvg(double[], int);

int main()
{
    const int SIZE = 7;
    static double score[SIZE];
    int x;

    for (x = 1; x<=SIZE; x++)
    {
        getJudgeData(score[x]);
    }
    cout<< endl;
    calcAvg(score, SIZE);
    cout<< endl;
    return 0;
}

void getJudgeData(double & score)
{
    double judgeScore;
    static int judgeNumber = 1;
    cout<< "Enter the Score from Judge #" << judgeNumber << ": ";
    cin>> judgeScore;
    
    while ((judgeScore<0) || (judgeScore>10))
    {
        cout<< "Error. Score must between 0 and 10." << endl;
        cout<< "Enter the Score from Judge #" << judgeNumber << ": ";
        cin>> judgeScore;
    }
    score = judgeScore;
    judgeNumber++;
}

double lowestScore(double score[], int SIZE)
{
    double min = score[1];
    int spot = 0;
    for (int x = 1; x <= SIZE; x++)
    {
        if (min > score[x])
        {
            min = score[x];
            spot = x;
        }
    }
    return min;
}

double highestScore(double score[], int SIZE)
{
    double max = score[1];
    int spot = 1;
    for (int x = 1; x <= SIZE; x++)
    {
        if (max < score[x])
        {
            max = score[x];
            spot = x;
        }
    }
    return max;
}

void calcAvg(double score[], int SIZE)
{
    int numberOfVotes = SIZE - 2;
    double sum = 0;
    double average;
    double lowScore = lowestScore(score, SIZE);
    double highScore = highestScore(score, SIZE);
    
    for (int x =1; x<= SIZE; x++)
    {
        sum += score[x];
    }
    
    cout<< "The lowest score is: " << lowScore << endl;
    cout<< "The highest score is: " << highScore << endl;
    
    average = ((sum - (highScore + lowScore)) / numberOfVotes);
    cout<< "The average score is: " << setprecision(2) << fixed << average << endl;
}
