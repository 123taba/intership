#include <iostream>
#include <string>
using namespace std;
const int herd = 2;
class CowRecord {
protected:
   float total = 0;
   int record_ID;
   float milk_yield[7][2]; 
public:
  int getRecordID() 
  { 
    return record_ID;
   }
   float get_milkyield()
   {
   	return milk_yield[7][2];
   }
    int RecordCowData(int cow_number)
{
     cout << "Enter Data of Record ID " << cow_number + 1 << " Cow : ";
        cin >> record_ID; 
   
	    for (int j = 0; j < 7; j++)  
		{
		 
        for (int k = 0; k < 2; k++) 
		{
                cout << "Enter milk yield for Day " << j + 1 << "  Milking cycle  " << k + 1 << " :   ";
                cin >> milk_yield[j][k];
        }
        }
    }

	


    float TotalYield() 
	{
       
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 2; j++) {
                total += milk_yield[i][j];
            }
        }
        return total;
    }

    float AverageYield() {
        return total / 14; 
    }
};

class Statistics {
public:
    static float WeeklyVolume(CowRecord records[]) {
        float total = 0;
        for (int i = 0; i < herd; i++) {
            total += records[i].TotalYield();
        }
        return total;
    }

    static float AverageYield(CowRecord records[]) {
        float total = 0;
        for (int i = 0; i < herd; i++) {
            total += records[i].TotalYield();
        }
        return total / herd;
    }
};

class Productivity {
public:
    static void MostProductiveCow(CowRecord records[])
	 {
        int most_productive = 0;
        float highest_yield = records[0].TotalYield();
        for (int i = 1; i < herd; i++) 
		{
            float current_yield = records[i].TotalYield();
            if (current_yield > highest_yield)
			 {
                highest_yield = current_yield;
                most_productive = i;
            }
        }
        cout << "Most productive cow is with Record ID " << records[most_productive].getRecordID() << " with total yield of " << highest_yield << " liters.\n";
    }

    static void LowYieldCows(CowRecord records[])
	 {
        for (int i = 0; i < herd; i++) 
		{
            int low_yield_days = 0;
            for (int j = 0; j < 7; j++) 
			{
                for (int k = 0; k < 2; k++)
				 {
                    if (records[i].get_milkyield() < 12.0) 
					{
                        low_yield_days++;
                    }
                }
            }
            if (low_yield_days >= 4) {
            cout << "Cow with Record ID " << records[i].getRecordID() << " has produced less than 12 litres of milk on four or more days this week.\n";
            }
        }
    }
};
int main() {
    CowRecord records[herd];
    Statistics stats;
    Productivity productivity;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Record milk yield for a cow\n";
        cout << "2. Calculate total weekly volume and average yield per cow\n";
        cout << "3. Identify the most productive cow and cows with low yield\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	  for (int i = 0; i < herd; i++) 
				{
                   records[i].RecordCowData(i);
               }
            
                break;
            case 2:
                cout << "\n\nTotal weekly volume of milk for the herd: " << stats.WeeklyVolume(records) << " liters.\n\n";
                cout << "\n\nAverage yield per cow in a week: " << stats.AverageYield(records) << " liters.\n\n";
                break;
            case 3:
                productivity.MostProductiveCow(records);
                productivity.LowYieldCows(records);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
