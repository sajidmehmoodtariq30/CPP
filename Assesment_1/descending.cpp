// program to arrange three number in descending order
// Standard Libraries
#include <iostream>

// Namespace Declaration
using namespace std;

// Main Function
int main() {
    // Variable declarations
    int n1,n2,n3;
    // Input
    cout<<"Enter the first number: ";
    cin>>n1;
    cout<<"Enter the second number: ";
    cin>>n2;
    cout<<"Enter the third number: ";
    cin>>n3;
    // Sorting
    if(n1>n2 && n1>n3)
    {
        if(n2>n3)
            cout<<"The numbers in descending order are: "<<n1<<" "<<n2<<" "<<n3;
        else
            cout<<"The numbers in descending order are:"<<n1<<" "<<n3<<" "<<n2;
    }
    else if(n2>n1 && n2>n3)
    {
        if(n1>n3)
            cout<<"The numbers in descending order are: "<<n2<<" "<<n1<<" "<<n3;
        else
            cout<<"The numbers in descending order are: "<<n2<<" "<<n3<<" "<<n1;
    }
    else if(n3>n1 && n3>n2)
    {
        if(n1>n2)
            cout<<"The numbers in descending order are: "<<n3<<" "<<n1<<" "<<n2;
        else
            cout<<"The numbers in descending order are:"<<n3<<" "<<n2<<" "<<n1;
    }
    else
        cout<<"All are equal";
    
    // Exiting the program
    return 0;
}