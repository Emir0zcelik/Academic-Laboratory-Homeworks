#include <iostream>
#include <string>

using namespace std;

#define MAX 50

class Queue{
	private:
		char items[MAX];
		int front;
		int rear;
		int size;
		int count;
	public:
		Queue(): front(0), rear(-1), size(0), count(0) {}
		
		bool isEmpty()
		{
			return front>rear;
		}
		
		bool isFull()
		{
			return rear == MAX -1;
		}
		
		bool enqueue(char data)
		{
			if(isFull())
			{
				return false;
			}
			
			items[++rear] = data;
			size++;
			return true;
		}
		
		bool dequeue(char &data)
		{
			if(isEmpty())
			{
				return false;
			}
			
			data = items[front++];
			size--;
			return true;
		}
		
		bool encrypt (char data)
		{
			items[count] += ((int) data - 48);
			count++;
		}
		
		bool decrypt (char data)
		{
			if((int)items[count] - ((int)data - 48) < 65 )
			{
				items[count] -= ((int) data - 48) + 26;
				count++;
			}
			
			else
			{
				items[count] -= ((int) data - 48);
				count++;
			}
		}
		
		int get_size()
		{
			return size;
		}
};

void mainMenu()
{
	cout << "1. Encrypt Text" << endl;
	cout << "2. Decrypt Text" << endl;
	cout << "3. Exit" << endl;
}

int main()
{
	Queue que1; // Phrase
	Queue que2; // KEY
	
	string str1, str2;
	int choice, size1, size2;
	do
	{
		mainMenu();
		cout << "Your choice: ";
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "Enter your text: ";
			cin >> str1;
				
				
			for (int i = 0; i < str1.length(); i++)
			{
				que1.enqueue(str1[i]);
			}
				
			cout << "Enter your key: ";
			cin >> str2;
			int i = 0;
			
			while(i < str1.length())
			{
				for(int j = 0; j <str2.length(); j++)
				{
					if(que2.get_size() == que1.get_size())
					{
						break;
					}
					que2.enqueue(str2[j]);
				}
				i = i + str2.length();
			}
			
			size1 = que1.get_size();
			size2 = que2.get_size();
			
			char first;
		
			
			for(int i = 0; i < size2; i++)
			{
				que2.dequeue(first);
				que1.encrypt(first);
			}
			
			char encstr;
			
			for (int i = 0; i < size1; i++)
			{
				que1.dequeue(encstr);
				cout << encstr;
			}
			
			cout << endl;
		}
		
		else if(choice == 2)
		{
				cout << "Enter your text: ";
			cin >> str1;
				
				
			for (int i = 0; i < str1.length(); i++)
			{
				que1.enqueue(str1[i]);
			}
				
			cout << "Enter your key: ";
			cin >> str2;
			int i = 0;
			
			while(i < str1.length())
			{
				for(int j = 0; j <str2.length(); j++)
				{
					if(que2.get_size() == que1.get_size())
					{
						break;
					}
					que2.enqueue(str2[j]);
				}
				i = i + str2.length();
			}
			
			size1 = que1.get_size();
			size2 = que2.get_size();
			
			char first;
		
			
			for(int i = 0; i < size2; i++)
			{
				que2.dequeue(first);
				que1.decrypt(first);
			}
			
			char dencstr;
			
			for (int i = 0; i < size1; i++)
			{
				que1.dequeue(dencstr);
				cout << dencstr;
			}
			
			cout << endl;
		}
		
		else
		{
			while(choice != 3)
			{
				cout << "Please enter a valid choice!!!" << endl;
				break;
			}	
		}
	}while(choice != 3);
	 
	cout << "Bye!" << endl;
	
	return 0;
}
