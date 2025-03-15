#include <iostream>

using namespace std;

int getLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char* Concatinate(char str1[], char str2[]) {
    int length1 = getLength(str1);
    int length2 = getLength(str2);

    int totalLength = length1 + length2 + 1;

    char* result = new char[totalLength];

    for (int i = 0; i < length1; i++)
        result[i] = str1[i];

    for (int i = 0; i < length2; i++)
        result[length1 + i] = str2[i];

    result[totalLength - 1] = '\0';

    return result;
}

int main() {
    const int maxLength = 100;
    char str1[maxLength];
    char str2[maxLength];

    cout << "Enter the first string: ";
    cin.getline(str1, maxLength);

    cout << "Enter the second string: ";
    cin.getline(str2, maxLength);

    char* result = Concatinate(str1, str2);
    cout << "Concatenated String: " << result << endl;

    delete[] result;

    return 0;
}