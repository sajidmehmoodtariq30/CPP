#include <iostream>

using namespace std;

struct Product
{
    int ProductID;
    char name[50];
    float price;
};

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

Product *findProduct(char name[50],Product *productptr);

int main()
{
    Product *productptr = new Product[5];
    const int maxLength = 50;
    char name[50];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter data for " << i + 1 << " Product" << endl;
        cout << "Enter ProductID: ";
        cin >> productptr[i].ProductID;
        cout << "Enter the name of product: ";
        cin.ignore();
        cin.getline(productptr[i].name, maxLength);
        cout << "Enter the price of product: ";
        cin >> productptr[i].price;
    }
    cout << "Enter name of the product you want to find: ";
    cin.ignore();
    cin.getline(name, maxLength);

    Product *newProductptr = findProduct(name,productptr);

    cout << newProductptr->ProductID;
    cout << newProductptr->price;
    cout << newProductptr->name;

    return 0;
}

Product *findProduct(char name[50],Product *productptr){
    Product *newProductptr;
    bool value;
    for (int  i = 0; i < 5; i++)
    {
        value = strComp(name,productptr[i].name);
        if (value)
        {
            *newProductptr = productptr[i];
            return newProductptr;
        }
        
    }
    return nullptr;
}