#include <iostream>

using namespace std;

#define MAX 50

class Queue{
	private:
		int items[MAX];
		int front;
		int rear;
		int size;
	public:
		Queue(): front(0) , rear(-1), size(0) {}
		
		bool isEmpty(){
			return front > rear;
		}
		
		bool isFull(){
			return rear == MAX - 1;
		}
		
		bool enqueue(int data){
			if(isFull())
				return false;
			items[++rear] = data;
			size++;
			return true;
		}
		
		bool dequeue(int &data)
		{
			if(isEmpty())
				return false;
			data = items[front++];
			size--;
			return true;
		}
		
		void print(){
			if(isEmpty())
				return;
			for(int i = 0; i < size; i++)
			{
				cout << items[i] << " ";
			}
			cout << endl;
		}
};

void invert(Queue queue1, Queue &queue2){
	
	int x;
	
	queue1.dequeue(x);
	if(!queue1.isEmpty())
	{
		invert(queue1, queue2);
	}
	queue2.enqueue(x);
	return;
}

int main(){
	Queue que1;
	Queue que2;
	int data;
	
	cout << "Fill your queue:";
	do{
		cin >> data;
		if(data == -1)
		{
			break;
		}
		que1.enqueue(data);
	}while(data != -1);
	cout << "Original queue: ";
	que1.print();
	invert(que1, que2);
	cout << "Inverted queue: "; 
	que2.print();	
	return 0;
}
