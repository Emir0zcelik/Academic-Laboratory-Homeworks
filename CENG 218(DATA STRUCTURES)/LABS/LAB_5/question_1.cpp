#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 50

class Queue {
	private:
		char items[MAX];
		int front;
		int rear;
		int size;
	public:
		Queue(): front(0), rear(-1), size (0) {}
		
		bool isEmpty()
		{
			return front>rear;
		}
		
		bool isFull()
		{
			return rear == MAX - 1;
		}
		
		bool enqueue(char data)
		{
			if(isFull())
			{
				return false;
			}
				
			items[++rear] = data;
			return true;
		}
		
		void dequeue()
		{
			int i = 0;
			
			while(items[i] != '.')
			{
				if (items[i] == items[i + 1])
				{
					items[i + 1] = items[i];
				}
				i++;
			}
		}
				
		void print()
		{
			int i = 0;
			while(items[i] != '.')
			{
				cout << items[i] << " ";
				i++;
			}
		}
		
		int get_size()
		{
			int i = 0;
			while(items[i] != '.')
			{
				size++;
				i++;
			}
			return size;
		}
		
		void printDroppedChars()
		{
			int i = 0;
			while(items[i] != '.')
			{
				if(items[i] == items[i + 1])
				{
					cout << items[i] << " ";
				}
				i++;
			}
			cout << endl;
		}
		
};

int main()
{
	Queue que;
	Queue final;
	char str;
	string s;
	int size = 0 ,sizef = -1;
	cout << "Enter: ";
	
	while(str != '.' && size < 50)
	{
		cin >> str;
		s += str;
		que.enqueue(str);
		size++;
	}
	
	for(int i = 0; i < size; i++)
	{
		if(s[i] != s[i+1])
		{
			final.enqueue(s[i]);
			sizef++;
		}
	}
	cout << "Initial size of queue: ";
	cout << que.get_size() << endl;
	cout << "Dropped chars: ";
	que.printDroppedChars();
	que.dequeue();
	cout << "Final size of queue: " << sizef;
	cout << endl;
	cout << "Final queue: ";
	final.print();
	
}
