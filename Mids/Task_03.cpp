#include <iostream>
using namespace std;

int main()
{
    const int n = 3;

    int matrix[n][n];

    // Input elements of the matrix
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
        cout << "Orignal matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        
        cout << endl;
    }

    // Rotate the matrix by 90 degrees clockwise
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Then, we will reverse each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }

    // Output the rotated matrix
    cout << "Rotated matrix by 90 degrees clockwise:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }

    return 0;
}