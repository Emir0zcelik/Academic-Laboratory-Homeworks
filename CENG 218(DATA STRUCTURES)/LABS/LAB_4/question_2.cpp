#include <iostream>
#include <math.h>
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

	bool push(int item) {
		if (isFull())
			return false;
		items[++top] = item;
		return true;
	}

	bool pop(int &item) {
		if (isEmpty())
			return false;
		item = items[top--];
		return true;
	}

	bool peek(int &item) {
		if (isEmpty())
			return false;
		item = items[top];
		return true;
	}
};

void decToBin(int n)
{
	Stack stk;
	int dec = 0, i = 0, temp;
	
	while(n != 0)
	{
		temp = n % 10;
		n /= 10;
		dec += temp * pow(2, i);
		++i;
	}
	stk.push(dec);
	
	while(!stk.isEmpty())
	{
		int item;
		stk.pop(item);
		cout << item;
	}
	cout << endl;
	
}

int main() {
	int number, count;
	
	cout << "Enter how many binary number you want to translate:";
	cin >> count;
	
	for(int i = 0; i < count; i++)
	{
		cout << "Enter an binary number: " << endl;
		cin >> number;
		decToBin(number);
	}
	return 0;
}
