#include <iostream>
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

typedef struct node {
	int data;
	struct node *next;
} Node;

class StackLinkedList {
private:
	Node *top;

	Node* createNode(int data) {
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}
public:
	StackLinkedList() :
			top(NULL) {
	}

	bool isEmpty() {
		return top == NULL;
	}

	bool isFull() {
		return false;
	}

	bool push(int item) {
		Node *newNode = createNode(item);
		newNode->next = top;
		top = newNode;
		return true;
	}

	bool pop(int &item) {
		if (isEmpty())
			return false;

		item = top->data;
		Node *tmp = top;
		top = top->next;
		delete tmp;
		return true;
	}

	bool peek(int &item) {
		if (isEmpty())
			return false;
		return top->data;
	}

};

void intToBinary (int n)
{
	StackLinkedList stk;
	
	while (n > 0) {
		int temp = n % 2;
		n = n / 2;
		stk.push(temp);
	}
	
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
	
	cout << "Enter how mant integer you want to translate:";
	cin >> count;
	
	for(int i = 0; i < count; i++)
	{
		cout << "Enter an integer: " << endl;
		cin >> number;
		intToBinary(number);
	}
	return 0;
}
