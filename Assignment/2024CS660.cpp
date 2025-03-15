#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Constants
const int ROWS = 15;
const int SEATS_PER_ROW = 30;

// Function to load data from file
bool loadFromFile(char seating[ROWS][SEATS_PER_ROW], double rowPrices[ROWS], double &totalRevenue, int &seatsSold, string &filename)
{
    ifstream file(filename);
    // Returning flase if data is not present in the file
    if (!file)
        return false;

    // Getting the seating chart from file
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < SEATS_PER_ROW; j++)
            file >> seating[i][j];

    // Getting row prices from file
    for (int i = 0; i < ROWS; i++)
        file >> rowPrices[i];
    // Getting Total Revenue from file
    file >> totalRevenue;
    // Getting Number of seats sold from file
    file >> seatsSold;
    // Closing the file
    file.close();

    return true;
}

// Function to initialize the seating chart
void initializeSeatingChart(char seating[ROWS][SEATS_PER_ROW])
{
    // Initializing all the seats with # considering every seat is available
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < SEATS_PER_ROW; j++)
            seating[i][j] = '#';
}

// Function to input prices for each row if they are not already present in file
void inputRowPrices(double rowPrices[ROWS])
{
    // Structuring the output
    for (int i = 0; i < ROWS; i++)
    {
        if (i == 0)
            cout << "Enter Price for 1st Row: ";
        else if (i == 1)
            cout << "Enter Price for 2nd Row: ";
        else if (i == 2)
            cout << "Enter Price for 3rd Row: ";
        else
            cout << "Enter Price for " << i + 1 << " Row: ";
        cin >> rowPrices[i];
    }
}

// Main Menue
void showMenu()
{
    cout << "Press 1 to Display seating chart" << endl;
    cout << "Press 2 to Sell Tickets" << endl;
    cout << "Press 3 to Display Statistics" << endl;
    cout << "Press 4 to save to file and exit." << endl;
    cout << "Enter you choice: ";
}

void displaySeatingChart(char seating[ROWS][SEATS_PER_ROW])
{
    // Printing seat numbers
    cout << "       ";
    for (int i = 0; i < SEATS_PER_ROW/3; i++)
        cout << setw(2) << i;
    for (int i = 0; i < SEATS_PER_ROW/3; i++)
        cout << setw(2) << i;
    for (int i = 0; i < SEATS_PER_ROW/3; i++)
        cout << setw(2) << i;
    cout << endl;
    // Printing Seats where # represents available and * represents sold
    for (int i = 0; i < ROWS; i++)
    {
        cout << "Row " << setw(2) << i + 1 << "\t";

        for (int j = 0; j < SEATS_PER_ROW; j++)
            cout << seating[i][j] << " ";

        cout << endl;
    }
}

void displayStatistics(char seating[ROWS][SEATS_PER_ROW], double &totalRevenue, int &seatsSold)
{
    int seatsAvailable[ROWS] = {0};
    int temp;
    cout << "Total Revenue Generated from ticket Sales is: " << totalRevenue << endl;
    cout << "Total number of seats sold are: " << seatsSold << endl;
    cout << "Total number of available seats in complete theater is: " << (15 * 30) - seatsSold << endl;
    for (int i = 0; i < ROWS; i++)
    {
        temp = 0;
        for (int j = 0; j < SEATS_PER_ROW; j++)
            if (seating[i][j] == '#')
                temp++;

        seatsAvailable[i] = temp;
    }

    for (int i = 0; i < ROWS; i++)
        cout << seatsAvailable[i] << " seats available in Row " << i + 1 << endl;
}

void saveToFile(char seating[ROWS][SEATS_PER_ROW], double rowPrices[ROWS], double &totalRevenue, int &seatsSold, string &filename)
{
    ofstream file(filename);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < SEATS_PER_ROW; j++)
            file << seating[i][j] << " ";
        file << endl;
    }
    for (int i = 0; i < ROWS; i++)
        file << rowPrices[i] << " ";
    file << endl;
    file << totalRevenue << endl;
    file << seatsSold << endl;
    file.close();
}

// Function to sell tickets
void sellTickets(char seating[ROWS][SEATS_PER_ROW], double rowPrices[ROWS], double &totalRevenue, int &seatsSold)
{
    int row, seat;
    cout << "Enter the row number (1 to " << ROWS << "): ";
    cin >> row;

    // Input validation for row number
    while (row < 1 || row > ROWS)
    {
        cout << "Invalid row number. Please enter a number between 1 and " << ROWS << ": ";
        cin >> row;
    }

    cout << "Enter the seat number (1 to " << SEATS_PER_ROW << "): ";
    cin >> seat;

    // Input validation for seat number
    while (seat < 1 || seat > SEATS_PER_ROW)
    {
        cout << "Invalid seat number. Please enter a number between 1 and " << SEATS_PER_ROW << ": ";
        cin >> seat;
    }

    // Adjusting for zero-based indexing
    row--;
    seat--;

    // Check if the seat is available
    if (seating[row][seat] == '#')
    {
        // Mark seat as sold
        seating[row][seat] = '*';
        // Update total revenue and seats sold
        totalRevenue += rowPrices[row];
        seatsSold++;
        cout << "Ticket sold for Row " << row + 1 << ", Seat " << seat + 1 << " at price $" << rowPrices[row] << endl;
    }
    else
        cout << "Sorry, this seat is already sold. Please choose another seat.\n";
}

int main()
{
    char seating[ROWS][SEATS_PER_ROW];
    double rowPrices[ROWS] = {0};
    double totalRevenue = 0.0;
    int seatsSold = 0;

    string filename = "theater_data.txt";

    // Load data from file or initialize defaults
    if (!loadFromFile(seating, rowPrices, totalRevenue, seatsSold, filename))
    {
        // initializing seating chart in case if it is not already present in file
        initializeSeatingChart(seating);
        // Getting Row prices from user in case if they are not found in file
        inputRowPrices(rowPrices);
    }

    int choice;
    do
    {
        system("cls");
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            displaySeatingChart(seating);
            system("pause");
            break;
        case 2:
            sellTickets(seating, rowPrices, totalRevenue, seatsSold);
            system("pause");
            break;
        case 3:
            displayStatistics(seating, totalRevenue, seatsSold);
            system("pause");
            break;
        case 4:
            saveToFile(seating, rowPrices, totalRevenue, seatsSold, filename);
            cout << "Data saved. Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}