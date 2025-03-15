#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Print the top half of the shape
    for (int i = 0; i < n / 2 ; i++) {
        // Print spaces
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        // Print stars
        for (int j = 0; j < n - 2 * i; j++) {
            cout << "* ";
        }
        
        cout << endl;
        
    }
    if(n%2 == 0)
        {
            for(int k = 0; k<n-1;k++)
                cout << " ";
            cout << "*";
            cout << endl;
        }
    
    // Print the bottom half of the shape
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Print spaces
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        // Print stars
        for (int j = 0; j < n - 2 * i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}