#include<iostream>
#include<cmath>
int total_citizens;
int Cares_for_outing;
using namespace std;
int total_citizen;
int Care_for_outing=0;


//Task#1
class Citizen_information
{ 
protected:

double total_cost_meal;
double cost_for_coach;
double cost_for_tickets;
double Total_cost;
public:
	int set_Care_for_outing(int care_by_default)
	{
		Cares_for_outing=care_by_default;
	}
void Citizens_Information()
{
	cout<<"\n Enter total Number of Citizens for Outing : \n";
	cin>>total_citizens;
	
	if(total_citizens<10 || (total_citizens > 36))
	{
		cout<<"\n Minimum Citizens required to go out for outing  are 10 .\n";
		cout<<"\n Enter valid Number of Citizens .\n";
	do
	{ 
	  cout<<"\n ReEnter total Number of Citizens for Outing : \n";
	  cin>>total_citizens;	
	}while((total_citizens)<10||(total_citizens)>=36);
	
    }
	else if(total_citizens>24)
	{
		Cares_for_outing++;
		
	} 
}
int calculate_information(int total_citizens)
{
	cout<<"\n Calculated Total Cost of Outing Through "<<total_citizens<<". \n\n ";
	if(total_citizens>=11||total_citizens<=16)
	{
	total_cost_meal=14.00;
    cost_for_coach=150;
 cost_for_tickets=21.00;
	}
	else if(total_citizens>=17||total_citizens<=26)
	{
	total_cost_meal=13.50;
    cost_for_coach=190;
 cost_for_tickets=20.00;
	}
	else if(total_citizens>=27||total_citizens<=39)
	{
	total_cost_meal=13.00;
    cost_for_coach=225;
 cost_for_tickets=19.00;
	}
	Total_cost=total_citizens*total_cost_meal*cost_for_tickets;
	return Total_cost;
}
};
class ParticipantRecorder {
public:
    int recordParticipants(int total_citizens) {
        string names[total_citizens];
        double amountsPaid_for_meal[total_citizens];
        double amountsPaid_for_ticket[total_citizens];
        
       
        cout<<"______________________________________________________________\n";
        cout<<"\nNo of people  : "<<" Cost for Outing   : "<<" Ticket Amount \n\n";
        cout<<" \n 12-16       : "<<"14.00              :" << " 21.00\n";
        cout<<" \n  17-26      : "<<" 13.50             :" << " 20.00\n";
        cout<<" \n 27-36       : "<<"13.00              :" << " 19.00\n\n";
        cout<<"______________________________________________________________\n";

        for (int i = 0; i < total_citizens; i++) 
		{
             cout << "Enter name of Senior_citizen " << i + 1 << ": ";
            cin >> names[i];
            cout << "Enter amount for meal  paid by " << names[i] << ": ";
            cin >> amountsPaid_for_meal[i];
            cout << "Enter amount for ticket  paid by " << names[ i] << ": ";
            cin >> amountsPaid_for_ticket[i];
            
        }

        for (int i = 0; i < Cares_for_outing; i++) {
            cout << "Enter name of carer " << i + 1 << ": ";
            cin >> names[ i];
            
        }

        cout << "\nList of participants and amounts paid:\n";
        for (int i = 0; i < total_citizens +  Cares_for_outing; i++) 
		{
            cout << names[i] <<"\t      $ " << amountsPaid_for_meal[i] + amountsPaid_for_ticket[i] << endl;
        }

        double totalAmountCollected = 0;
        for (int i = 0; i < total_citizens +  Cares_for_outing; i++) 
		{
            totalAmountCollected += amountsPaid_for_meal[i]+amountsPaid_for_ticket[i];
        }
        cout << "\nTotal amount collected: $" << totalAmountCollected << endl;
    }
};
class OutingProfitCalculator
 {
public:
    void calculateProfit(double totalCost, double totalAmountCollected) 
	{
        if (totalAmountCollected >= totalCost) {
            double profit = totalAmountCollected - totalCost;
            cout << "The outing has made a profit of $" << profit << endl;
        } else {
            double loss = totalCost - totalAmountCollected;
            cout << "The outing has incurred a loss of $" << loss << endl;
        }
    }
};
int main() 
{
    Citizen_information citizenInfo;
    ParticipantRecorder participantRecorder;
    OutingProfitCalculator profitCalculator;
    int choice;

    do {
        cout << "\nMenu:";
        cout << "\n1. Enter Citizens Information (Task 1)";
        cout << "\n2. Record Participants (Task 2)";
        cout << "\n3. Calculate Profit (Task 3)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
         double total_cost;
         double user_cost;
        switch (choice) {
            case 1:
                citizenInfo.Citizens_Information();
                citizenInfo.set_Care_for_outing(2);
                total_cost=citizenInfo.calculate_information(total_citizens);
                break;
            case 2:
               user_cost= participantRecorder.recordParticipants(total_citizens);
                break;
            case 3:
                profitCalculator.calculateProfit(total_cost,user_cost) ;
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}



