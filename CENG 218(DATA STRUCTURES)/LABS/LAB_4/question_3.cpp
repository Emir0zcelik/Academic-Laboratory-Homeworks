#include <iostream>
#include <string>

using namespace std;

#define MAX 50
class Stack {
private:
	int items[MAX];
	int top;
public:
	Stack() :
			top(-1) {
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == (MAX-1);
	}

	bool push(char item) {
		if (isFull())
			return false;
		items[++top] = item;
		return true;
	}

	bool pop(char &item) {
		if (isEmpty())
			return false;
		item = items[top--];
		return true;
	}
	
	bool balanced()
	{
		int countLeft = 0, countRight = 0;
		
		if(isEmpty())
		{
			cout << "Stack is empty." << endl;
			return false;
		}
		
		int i = 0;
		while(i <= top)
		{
			if(items[i] == '(')
			{
				countLeft++;
			}
			
			else if(items[i] == ')')
			{
				countRight++;
			}
			i++;
		}
		
		if(countLeft == countRight)
		{
			cout << "The string is balanced." << endl;
			return true;
		}
		
		else 
		{
			cout << "The string is not balanced." << endl;
			return false;
		}
	}
};


int main()
{
	Stack stk;
	string x;
	
	cout << "Enter your string:";
	cin >> x;
	
	for(int i = 0; i < x.size(); i++)
	{
		stk.push(x[i]);
	}
	
	stk.balanced();
	
	return 0;
}
