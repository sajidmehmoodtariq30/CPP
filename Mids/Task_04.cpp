#include <iostream>
using namespace std;

int main()
{
    const int rows = 3, cols = 5;
    int marks[rows][cols] = {
        {5, 7, 8, 3, 4}, // quiz1
        {6, 4, 9, 1, 2}, // quiz2
        {8, 2, 4, 7, 9}  // quiz3
    };


    // int marks[rows][cols];
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << "Enter element [" << i << "][" << j << "]: ";
    //         cin >> marks[i][j];
    //     }
    // }


    cout << endl;
    cout << "\ts1\ts2\ts3\ts4\ts5" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "quiz" << i + 1 << "\t";
        for (int j = 0; j < cols; j++)
        {
            cout << marks[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        int maxMarks = marks[i][0], minMarks = marks[i][0];
        int maxPos = 0, minPos = 0;
        for (int j = 1; j < cols; j++)
        {
            if (marks[i][j] > maxMarks)
            {
                maxMarks = marks[i][j];
                maxPos = j;
            }
            if (marks[i][j] < minMarks)
            {
                minMarks = marks[i][j];
                minPos = j;
            }
        }
        cout << "Quiz " << i + 1 << ": Max = " << maxMarks << " at s" << maxPos + 1
             << ", Min = " << minMarks << " at s" << minPos + 1 << endl;
    }

    int highestStudent = 0, highestMarks = 0;
    for (int j = 0; j < cols; j++)
    {
        int studentTotal = 0;
        for (int i = 0; i < rows; i++)
        {
            studentTotal += marks[i][j];
        }
        if (studentTotal > highestMarks)
        {
            highestMarks = studentTotal;
            highestStudent = j;
        }
    }
    cout << "Student s" << highestStudent + 1 << " has the highest total marks: " << highestMarks << endl;

    return 0;
}
