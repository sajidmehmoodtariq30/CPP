#include<iostream> 
#include<string>
using namespace std;

bool strComp (char str1[], char str2[]);
int getLength(char str[]);


int main(){
    const int maxLength = 100;
    char str1[maxLength];
    char str2[maxLength];

    cout << "Enter the first string: ";
    cin.getline(str1, maxLength);

    cout << "Enter the second string: ";
    cin.getline(str2, maxLength);

    bool result = strComp(str1, str2);
    if(result)
        cout << "Equal";
    else
        cout << "Not Equal";
   return 0;
}

int getLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool strComp (char str1[], char str2[]){
    int length1 = getLength(str1);
    int length2 = getLength(str2);
    if (length1 != length2)
        return false;
    else{
        for (int i = 0; i < length1; i++)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
    
}