// a program that calculates the Least Common Multiple (LCM) of two positive integers
// Standard Libraries
#include <iostream>

// Namespace Declaration
using namespace std;

// Main Function
int main()
{
    // Variable declarations
    int n1, n2, i = 0, result;
    bool value = true;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;
    int a = n1;
    int b = n2;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;

    // Calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    result = (n1 * n2) / gcd;
    cout << result;
    // Exiting the program
    return 0;
}