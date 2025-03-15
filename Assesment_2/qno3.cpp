#include <iostream>
using namespace std;

int main() {
    int num, temp, sum;

    // Input the number
    cout << "Enter a number: ";
    cin >> num;

    // Store the original number
    temp = num;

    while (true) {
        // Calculate the sum of the squares of the digits
        sum = 0;
        while (temp != 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        // Check if the sum is 1
        if (sum == 1) {
            cout << num << " is a funny number." << endl;
            break;
        }

        // Check if a cycle is detected
        if (sum == num) {
            cout << num << " is a serious number." << endl;
            break;
        }

        // Update the number for the next iteration
        temp = sum;
    }

    return 0;
}