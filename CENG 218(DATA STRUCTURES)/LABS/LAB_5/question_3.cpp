#include <iostream>
#include <string>

using namespace std;

#define MAX 50

class Queue{
	private:
		int items[MAX];
		int front;
		int rear;	
	public:
		Queue(): front(0), rear(-1){}
		
		bool isEmpty()
		{
			return front > rear;
		}
		
		bool isFull()
		{
			return rear == MAX-1;
		}
	
		bool enqueue(int data)
		{
			if(isFull())
			{
				return false;
			}
			items[++rear] = data;
			return true;
		}
		
		bool dequeue(int &data)
		{
			if(isEmpty())
			{
				return false;
			}
			data = items[front++];
			return true;
		}
		
};

class Stack {
	private:
		int items[MAX];
		int top;
	public:
		Stack(): top(-1) {}
		
		bool isEmpty()
		{
			return top == -1;
		}
		
		bool isFull()
		{
			return top == (MAX-1);
		}
		
		bool push(int item)
		{
			if(isFull())
			{
				return false;
			}
			
			items[++top] = item;
			return true;
		}
		
		
		bool pop(int &item)
		{
			if(isEmpty())
			{
				return false;
			}
			
			item = items[top--];
			return true;
		}
		
};

int main()
{
	Stack stk;
	Queue que;
	
	string str;
	int p1 = 0, p2 = 0, count = 0;
	bool yes = false;
	
	cout << "Enter your string: ";
	cin >> str;
	
	for(int i = 0; i < str.length(); i++)
	{
		que.enqueue(str[i]);
		stk.push(str[i]);
	}
	
	for(int i = 0; i < str.length(); i++)
	{
		que.dequeue(p1);
		stk.pop(p2);
		
		
		if(p1 != p2)
		{
			cout << str << " is not a palindrome.";
			break;
		}
		else
		{
			yes = true;
		}
	}
	
	if(yes == true)
	{
		cout << str << " is a palindrome.";
	}
	

	return 0;
}
