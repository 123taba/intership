#include <iostream>
#include <string>

using namespace std;

// Constants for ticket prices
const double ADULT_ONE_DAY = 20.00;
const double CHILD_ONE_DAY = 12.00;
const double SENIOR_ONE_DAY = 16.00;
const double FAMILY_ONE_DAY = 60.00;
const double GROUP_ONE_DAY = 15.00;

const double ADULT_TWO_DAYS = 30.00;
const double CHILD_TWO_DAYS = 18.00;
const double SENIOR_TWO_DAYS = 24.00;
const double FAMILY_TWO_DAYS = 90.00;
const double GROUP_TWO_DAYS = 22.50;

// Constants for extra attractions
const double LION_FEEDING = 2.50;
const double PENGUIN_FEEDING = 2.00;
const double EVENING_BARBECUE = 5.00;

// Function to display ticket options and extra attractions
void displayOptions() {
    cout << "One-Day Tickets:\n";
    cout << "Adult: $" << ADULT_ONE_DAY << endl;
    cout << "Child: $" << CHILD_ONE_DAY << endl;
    cout << "Senior: $" << SENIOR_ONE_DAY << endl;
    cout << "Family: $" << FAMILY_ONE_DAY << endl;
    cout << "Group: $" << GROUP_ONE_DAY << endl;

    cout << "\nTwo-Day Tickets:\n";
    cout << "Adult: $" << ADULT_TWO_DAYS << endl;
    cout << "Child: $" << CHILD_TWO_DAYS << endl;
    cout << "Senior: $" << SENIOR_TWO_DAYS << endl;
    cout << "Family: $" << FAMILY_TWO_DAYS << endl;
    cout << "Group: $" << GROUP_TWO_DAYS << endl;

    cout << "\nExtra Attractions:\n";
    cout << "Lion Feeding: $" << LION_FEEDING << endl;
    cout << "Penguin Feeding: $" << PENGUIN_FEEDING << endl;
    cout << "Evening Barbecue: $" << EVENING_BARBECUE << endl;
}

// Function to calculate the total cost of a booking
double calculateTotalCost(int numTickets, int numDays, string ticketType, string extraAttraction) {
    double totalCost = 0.0;
    double ticketPrice = 0.0;

    if (numDays == 1) {
        if (ticketType == "adult") {
            ticketPrice = ADULT_ONE_DAY;
        } else if (ticketType == "child") {
            ticketPrice = CHILD_ONE_DAY;
        } else if (ticketType == "senior") {
            ticketPrice = SENIOR_ONE_DAY;
        } else if (ticketType == "family") {
            ticketPrice = FAMILY_ONE_DAY;
        } else if (ticketType == "group") {
            ticketPrice = GROUP_ONE_DAY;
        }
    } else if (numDays == 2) {
        if (ticketType == "adult") {
            ticketPrice = ADULT_TWO_DAYS;
        } else if (ticketType == "child") {
            ticketPrice = CHILD_TWO_DAYS;
        } else if (ticketType == "senior") {
            ticketPrice = SENIOR_TWO_DAYS;
        } else if (ticketType == "family") {
            ticketPrice = FAMILY_TWO_DAYS;
        } else if (ticketType == "group") {
            ticketPrice = GROUP_TWO_DAYS;
        }
    }

    totalCost += ticketPrice * numTickets;

    if (extraAttraction == "lion feeding") {
        totalCost += LION_FEEDING * numTickets;
    } else if (extraAttraction == "penguin feeding") {
        totalCost += PENGUIN_FEEDING * numTickets;
    } else if (extraAttraction == "evening barbecue" && numDays == 2) {
        totalCost += EVENING_BARBECUE * numTickets;
    }

    return totalCost;
}

// Function to process a booking
void processBooking() {
    int numTickets, numDays;
    string ticketType, extraAttraction;

    cout << "Enter number of tickets: ";
    cin >> numTickets;

    cout << "Enter number of days (1 or 2): ";
    cin >> numDays;
    if(numDays!=1 && numDays!=2)
    {
    	cout<<"\n You have entered invalid numDays please enter from 1 and 2 . \n ";
    	cin>>numDays;
	}

    cout << "Enter ticket type (adult/child/senior/family/group): ";
    cin >> ticketType;
    if(ticketType!="adult"&&ticketType!="child"&&ticketType!="senior"&&ticketType!="family"&&ticketType!="group")
    {
    cout << " You have Enter Invalid Type . Enter ticket type (adult/child/senior/family/group): ";
    cin >> ticketType;
	}

    cout << "Enter extra attraction (none/lion feeding/penguin feeding/evening barbecue): ";
    cin >> extraAttraction;
    getline(cin,extraAttraction);
 if(extraAttraction!="none"&&extraAttraction!="lion feeding"&&extraAttraction!="penguine feeding"&&extraAttraction!="evening barbecue")
    {
    cout << "Enter extra attraction (none/lion feeding/penguin feeding/evening barbecue): ";
    cin >> extraAttraction;
    getline(cin,extraAttraction);
   
	}

    double totalCost = calculateTotalCost(numTickets, numDays, ticketType, extraAttraction);

    cout << "Total cost of booking: $" << totalCost << endl;
}

int main() {
    cout << "Welcome to the Wildlife Park Ticket Booking a System!\n";

    int choice;

    do {
        cout << "\nMenu:\n"
             << "1. Display ticket options and extra attractions\n"
             << "2. Process a booking\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayOptions();
                break;
            case 2:
                processBooking();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

