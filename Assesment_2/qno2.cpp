#include <iostream>
using namespace std;

int main() {
    int start, end;

    // Input: range for strong numbers
    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;

    cout << "Strong numbers between " << start << " and " << end << " are: ";

    for (int num = start; num <= end; num++) {
        int originalNum = num;
        int sum = 0;

        // Calculate the sum of the factorial of the digits
        while (num > 0) {
            int digit = num % 10; // Extract the last digit
            int fact = 1;

            // Calculate factorial of the digit
            for (int i = 1; i <= digit; i++) {
                fact *= i;
            }

            sum += fact; // Add the factorial of the digit to sum
            num /= 10; // Remove the last digit
        }

        // Check if sum of factorials equals the original number
        if (sum == originalNum) {
            cout << originalNum << " "; // Print strong number
        }

        // Reset num for the next iteration
        num = originalNum;
    }
    
    cout << endl;

    return 0;
}