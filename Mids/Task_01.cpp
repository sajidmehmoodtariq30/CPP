#include <iostream>
using namespace std;

int main() {
    // Define the two arrays
    int A[5] = {2, 5, 3, 7, 6};
    int B[5] = {1, 5, 9, 3, 2};
    
    cout << "Intersection of arrays A and B: ";
    
    // Find intersection
    bool found;
    for (int i = 0; i < 5; i++) {
        found = false;
        for (int j = 0; j < 5; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << A[i] << " ";
        }
    }
    
    cout << endl;
    return 0;
}