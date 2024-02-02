
#include <iostream>
#include <string>

using namespace std;
const int maximum_pupil= 3;


void Student_data(double weights[], string names[]) {
cout << "Enter the weights and names for the class of 30 pupils:\n";
    for (int i = 0; i <maximum_pupil ; ++i) {
cout << "Enter weight for pupil " << i + 1 << " (in kilograms): ";
    cin >> weights[i];

        while (weights[i] <= 0) {
        cout << "Invalid weight. Please enter a positive value: ";
        cin >> weights[i];
        }

    cout << "Enter name for pupil " << i + 1 << ": ";
    cin.ignore();  // Ignore any previous newline character
    getline(cin, names[i]);
     
    }
}

void calculating_weight_difference(double weights[], double weightDifferences[]) {
    double lastDayWeight;
    for (int i = 0; i < maximum_pupil; ++i) {
        
    cout << "Enter weight on the last day of term for pupil " << i + 1 << " (in kilograms): ";
        cin >> lastDayWeight;
        while (lastDayWeight <= 0) 
        {
        cout << "Invalid weight. Please enter a positive value: ";
        cin >> lastDayWeight;
        }

        weightDifferences[i] = lastDayWeight - weights[i];
    }
}

void output_weight_difference(double weights[], string names[], double weightDifferences[]) {
  cout << "\nPupils with a weight difference of more than 2.5 kilograms:\n";
    bool check_student=false;
    for (int i = 0; i < maximum_pupil; ++i) 
	{
        if ((weightDifferences[i]) > 2.5)
        {
      cout << "Name: " << names[i] << ", Difference: " << weightDifferences[i]<< " kg! "  << "\n";
        }
        
    } if(!check_student)
       {
       	cout<<"\n No any student has difference!";
	   }
}

int main() {
    double weights[maximum_pupil];
    string names[maximum_pupil];
    double weightDifferences[maximum_pupil];
    cout<<"____________________________________________________________\n";
    cout<<"  1 . Enter 1 for input weight and names of students.        \n ";
    cout<<" 2 . Enter 2 for input weight on  last day of term .\n ";
    cout<<" 3 . Enter 3 for calculating difference in weight of students . \n ";
    cout<<"_____________________________________________________________\n";
    int choice;
    do {
cout << "\nEnter choice for Task completion (1, 2, 3, 0 to exit): ";
    cin >> choice;

        switch (choice) {
            case 1:
              Student_data(weights, names);
                break;
            case 2:
                calculating_weight_difference(weights, weightDifferences);
                break;
            case 3:
                output_weight_difference(weights, names, weightDifferences);
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
               cout << "Invalid choice! Please enter a valid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

