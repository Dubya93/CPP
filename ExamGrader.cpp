//
//  Description: Exam Grader
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


void getCorrectAnswers(char [], int);                               //  FilePath here
void getStudentAnswers(char[], int);                               //  FilePath here
void missedQuestions(char [], char [], int, double, double&);
void calcGrade(double&, int);


int main()
{
    int SIZE = 20;
    char correctAnswers[SIZE];
    char studentAnswers[SIZE];
    double totalMissedQuestions = 0;
    double totalCorrectQuestions = 0;
    getCorrectAnswers(correctAnswers, SIZE);
    getStudentAnswers(studentAnswers, SIZE);
    cout<< endl;
    missedQuestions(correctAnswers, studentAnswers, SIZE, totalMissedQuestions, totalCorrectQuestions);
    cout<< endl;
    calcGrade(totalCorrectQuestions, SIZE);
    
    cout<< endl << endl;
    return 0;
}

void getCorrectAnswers(char correctAnswers[], int SIZE)
{
    ifstream inputFile;
    string fileName;
    int x;
    
    cout<< "Enter filename for correct answers:" << endl;
    getline(cin,fileName);
    inputFile.open(fileName);
    while (!inputFile)
    {
        cout<< "File not found." << endl;
        cout<< "Enter filename for correct answers:" << endl;
        getline(cin,fileName);
    }
    
    for (x=1; x<=20; x++)
    {
        inputFile>> correctAnswers[x];
    }
    inputFile.close();                      // added the close file lines after the screenshots
}

void getStudentAnswers(char studentAnswers[], int SIZE)
{
    ifstream inputFile;
    string fileName;
    int x;
    
    cout<< "Enter filename for student answers:" << endl;
    getline(cin,fileName);
    inputFile.open(fileName);
    while (!inputFile)
    {
        cout<< "File not found." << endl;
        cout<< "Enter filename for student answers:" << endl;
        getline(cin,fileName);
    }
    
    for (x=1; x<=20; x++)
    {
        inputFile>> studentAnswers[x];
    }
    inputFile.close();                      // added the close file lines after the screenshots
}

void missedQuestions(char correctAnswers[], char studentAnswers[], int SIZE, double totalMissedQuestions, double& totalCorrectQuestions)
{
    totalMissedQuestions = 0;
    totalCorrectQuestions = 0;
    int x;
    int spot = 1;
    
    cout<< endl << "Question    Student     Correct" << endl;
    cout<< "Number      Answer      Answer" << endl;
    
    for (x=1; x<=SIZE; x++)
    {
        if (correctAnswers[x] != studentAnswers[x])
        {
            cout<< spot << "            " << studentAnswers[x] << "             " << correctAnswers[x] << endl;
            totalMissedQuestions++;
            spot++;
        }
        else
        {
            totalCorrectQuestions++;
            spot++;
        }
    }
    cout<< endl << totalMissedQuestions << " Incorrect Answers";
    cout<< endl << totalCorrectQuestions << " Correct Answers";
}

void calcGrade(double& totalCorrectQuestions, int SIZE)
{
    double grade;
    grade = (totalCorrectQuestions / SIZE) * 100;
    
    if (grade >= 70)
    {
        cout<< "This student passed the test with a " << grade << "%.";
    }
    else
    {
        cout<< "This student failed the test with a " << grade << "%.";
    }
}
