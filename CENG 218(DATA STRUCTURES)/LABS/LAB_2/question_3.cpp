#include <iostream>
#include <vector>

using namespace std;

class Flight {
	private:
		string name;
		int maximum_number_of_seats;
		int number_of_passengers;
		string list_of_passengers[25];
	public:
		Flight()
		{
			maximum_number_of_seats = 25;
			number_of_passengers = 0;
		}	
		
		void reserveSeat(string names)
		{	
			list_of_passengers[number_of_passengers] = names; 
			number_of_passengers++;
			cout << "Your reservation has been saved succesfully" << endl;
		}
		
		void cancelReservation(string name)
		{
			for (int i = 0; i < number_of_passengers; i++)
			{
				if(name == list_of_passengers[i])
				{
					list_of_passengers[i] = " ";
					number_of_passengers--;
					cout << "Your reservation has been canceled" << endl;
				}
			}
		}
		
		void numberOfPassengers()
		{ 
			cout << "Current number of passenger: " << number_of_passengers << " people." <<endl;
		}
		
		bool searchUser(string name)
		{
			for (int i = 0; i < number_of_passengers; i++)
			{
				if(name == list_of_passengers[i])
				{
					cout << name << " has an reservation in that flight." << endl; 
					return true;
				}
			}
			cout << name << " has not reservation in that flight." << endl;
			return false;
		}
		
		void printPassengers()
		{
			cout << "List of passengers: " << endl;
			for(int i = 0; i < maximum_number_of_seats ; i++)
			{
				if(i > number_of_passengers)
				{
					break;
				}
					
				cout << i + 1 << ". seat: " << list_of_passengers[i] << endl;
			}
		}
		
};

void mainMenu()
{
	cout << "1. Reserve a ticket" << endl;
	cout << "2. Cancel a reservation" << endl;
	cout << "3. Check whether a ticket is reserved for a particular person" << endl;
	cout << "4. Display the passengers" << endl;
	cout << "5. Exit" << endl;
}

int main()
{
	Flight x;
	int choice;
	string name, flight_no;
	cout << "Welcome to airline ticket reservation system!" << endl;
	
	
	do 
	{	
		mainMenu();
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1)
		{			
			cout << "Enter your flight no:";
			cin >> flight_no;
		
			cout << "Enter your name & surname:";
			cin >> name;
		
			x.reserveSeat(name);
			x.numberOfPassengers();
		}
		
		else if(choice == 2)
		{		
			cout << "Enter your flight no:";
			cin >> flight_no;
				
			cout << "Enter your name & surname:";
			cin >> name;
			
			x.cancelReservation(name);
			
		}
		
		else if(choice == 3)
		{	
			cout << "Enter your flight no:";
			cin >> flight_no;
		
			cout << "Enter the name & surname of person you want to search for reservation info: ";
			cin >> name;
			
			x.searchUser(name);
		}
		
		else if(choice == 4)
		{
			x.printPassengers(); 
		}
		
	}while (choice != 5);
	
	cout << "Bye!" << endl;
	
	return 0;
}
