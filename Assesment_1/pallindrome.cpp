// palindrome

#include <iostream>
using namespace std;

int main() {
    int num, originalNum, reversedNum = 0, remainder,sum=0;

    // Input the number from the user
    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;  // Store the original number for later comparison

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;           // Get the last digit
        sum+=remainder;
        reversedNum = reversedNum * 10 + remainder; // Append it to the reversed number
        num /= 10;                      // Remove the last digit from the original number

    }

    // Check if the original number and the reversed number are the same
    if (originalNum == reversedNum){
        cout << originalNum << " is a palindrome " ;
        if (originalNum % sum == 0)
            cout << "and is also a Harshad Number";
        else
            cout << "and is not a Harshad number";
    }
    return 0;
}