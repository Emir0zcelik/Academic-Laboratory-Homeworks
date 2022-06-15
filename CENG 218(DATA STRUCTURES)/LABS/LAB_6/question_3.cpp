#include <iostream>

using namespace std;

#define MAX 50

bool filterOut(string str);

class Stack {
	private:
		int items[MAX];
		int top;
		int size;
	public:
		Stack(): top(-1), size(0){}
		
		bool isEmpty(){
			return top == -1;
		}
		
		bool isFull(){
			return top == (MAX - 1);
		}
		
		bool push(int item){
			if(isFull())
			{
				return false;
			}
			
			items[++top] = item;
			size++;
			return true;
		}
		
		bool pop(int &item)
		{
			if(isEmpty())
			{
				return false;
			}
			
			item = items[top--];
			size--;
			return true;
		}
		
		bool filter(string str1)
		{
			int x;
			int i = 0;
			
			if(str1 == "even")
			{
				if(items[i] %2 != 0)
				{
						items[i] = items[i+1];
						i++;
				}	
			}
			
			else if(str1 == "odd"){
				if(items[i] %2 == 0)
				{
					items[i] = items[i+1];
					i++;
				} 
			}
			filterOut(str1);
		}
		
		void print()
		{
			for(int i = 0; i < size; i++)
			{
				cout << items[i] << " ";
			}
		}
};

bool filterOut(string str)
{
	if(str == "even")
	{
		cout << "even elements have been removed from stack" << endl;
		return true;
	}
	
	else
	{
		cout << "Odd elements have been removed from stack" << endl;
		return true;
	}
}

int main()
{
	Stack stk;
	int n;
	string select;
	
	cout << "Fill your stack: ";
	do
	{
		cin >> n;
		stk.push(n);
	}while(n != -1);
	cout << "Select 'even' or 'odd' to filter:";
	
	do
	{
		cin >> select;
		
		if(select == "even" || select == "odd")
		{
			break;
		}
		cout << "Please enter a valid choice!!" << endl;
	}while(select != "even" || select != "odd");
	stk.filter(select);
	stk.print();
	
	return 0;
}


