// a program to print the first n numbers in the Fibonacci sequence
// Standard Libraries
#include <iostream>

// Namespace Declaration
using namespace std;

// Main Function
int main()
{
    // Variable declarations
    int n1, n2,i=0,result,limit;
    bool value = true;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;
    cout << "Enter limit: ";
    cin >> limit;
    cout << n1 << n2;
    while (i<=limit - 3)
    {
        result = n1+n2;
        cout << result;
        n1 = n2;
        n2 = result;
        i++;
    }
    
    // Exiting the program
    return 0;
}