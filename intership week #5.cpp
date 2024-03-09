#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//TASK 1
int calculateCheckDigit(int num) {
    int total = 0;
    for (int i = 1; i <= 4; ++i) {
        int digit = (num / (int)pow(10, 4 - i)) % 10;
        total += digit * i;
    }
    return total % 11;
}

//TASK 2
bool validateParkingNumber(int num, int checkDigit) {
    return calculateCheckDigit(num) == checkDigit;
}

int main() {
    // Constants for prices and discounts
    const double pricePerHour[] = { 2.00, 10.00, 10.00, 10.00, 10.00, 10.00, 3.00 };
    const double discount[] = { 0.1, 0.5 };

    // Variables
    int day, arrivalHour, numHours, frequentParkingNum, checkDigit;
    double price, totalPayment = 0.0;

    // Display menu
    cout << "Car Park Payment System Simulation\n";
    cout << "----------------------------------\n";
    cout << "1. Calculate the price to park\n";
    cout << "2. Keep a total of the payments\n";
    cout << "3. Make payments fairer\n";
    cout << "4. Exit\n";

    int choice;
    do {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Task 1: Calculate the price to park
            cout << "\nEnter day (0-6, where 0=Sunday, 6=Saturday): ";
            cin >> day;
            cout << "Enter arrival hour (0-23): ";
            cin >> arrivalHour;
            cout << "Enter number of hours to park: ";
            cin >> numHours;
            cout << "Enter frequent parking number (0 if none): ";
            cin >> frequentParkingNum;

            // Validate frequent parking number
            if (frequentParkingNum != 0) {
                cout << "Enter check digit for frequent parking number: ";
                cin >> checkDigit;
                if (!validateParkingNumber(frequentParkingNum, checkDigit)) {
                    cout << "Invalid check digit. No discount applied.\n";
                    frequentParkingNum = 0; // Reset to no discount
                }
            }

            // Calculate price based on day, arrival hour, and number of hours
            if (arrivalHour < 0 || arrivalHour >= 24 || numHours <= 0 || numHours > 24) {
                cout << "Invalid input. Arrival hour should be between 0-23 and number of hours should be between 1-24.\n";
            } else {
                double priceBeforeDiscount = pricePerHour[day] * numHours;
                double discountAmount = priceBeforeDiscount * discount[arrivalHour >= 16 ? 1 : 0];
                price = priceBeforeDiscount - discountAmount;
                cout << fixed << setprecision(2) << "Price to park: $" << price << endl;
            }
            break;

        case 2:
            // Task 2: Keep a total of the payments
            totalPayment = 0.0; // Reset totalPayment at the start of the day
            do {
                double amountPaid;
                cout << "Enter amount paid: $";
                cin >> amountPaid;
                if (amountPaid >= price) {
                    totalPayment += amountPaid;
                    break;
                } else {
                    cout << "Amount paid should be greater than or equal to the price ($" << price << ").\n";
                }
            } while (true);
            cout << "Daily total payment: $" << totalPayment << endl;
            break;

        case 3:
            // Task 3: Make payments fairer
            cout << "\nEnter day (0-6, where 0=Sunday, 6=Saturday): ";
            cin >> day;
            cout << "Enter arrival hour (0-23): ";
            cin >> arrivalHour;
            cout << "Enter number of hours to park: ";
            cin >> numHours;

            // Calculate price before 16:00 and add evening charge
            if (arrivalHour < 0 || arrivalHour >= 24 || numHours <= 0 || numHours > 24) {
                cout << "Invalid input. Arrival hour should be between 0-23 and number of hours should be between 1-24.\n";
            } else {
                double priceBefore16 = pricePerHour[day] * numHours;
                double eveningCharge = (arrivalHour < 16) ? 0 : pricePerHour[day] * (numHours - (16 - arrivalHour));
                price = priceBefore16 + eveningCharge;
                cout << fixed << setprecision(2) << "Price to park: $" << price << endl;
            }
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}

