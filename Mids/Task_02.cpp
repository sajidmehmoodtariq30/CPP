#include <iostream>

using namespace std;

// Main Function
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i+1 << "th element: ";
        cin >> arr[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    
    
    return 0;
}