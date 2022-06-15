#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}Node;

class LinkedList {
	private:
		Node *head;
		
		
		Node* createNode(int data) { 
			Node *newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;
			return newNode;
		}
		
	public:
		LinkedList():head(NULL) {
			
		}
		
		void print(int small, int big) {
			Node *curr = head;
			
			if(small < big)
			{
				for(int i = 0; i < small - 1; i++)
				{
					curr = curr->next;
				}
				
				for (int i = 0; i < (big - small + 1); i++)
				{
					cout << curr->data << "->";
					curr = curr->next;
				}
				cout << "NULL" << endl;
			}
			
			else if(small > big)
			{
				for(int i = 0; i < big - 1; i++)
				{
					curr = curr->next;
				}
				
				for (int i = 0; i < (small - big + 1); i++)
				{
					cout << curr->data << "->";
					curr = curr->next;
				}
				cout << "NULL" << endl;
			}
				
				
		}
		
		void insertToEnd(int data, bool gate) {
			Node *newNode = createNode(data);
			if(head == NULL){
				head = newNode;
				return;
			}
			
			Node *curr = head;
			int smallest = curr->data;
			int countS = 1;
			int countB = 1;
			int bigg = curr->data;
			
			while(curr->next != NULL) {
				if(smallest <= curr->data)
				{
					curr = curr->next;	
				}
				
				else if(smallest > curr->data)
				{
					smallest = curr->data;
					curr = curr->next;	
				}
			}
			Node* currS = head;
			
			
			while(smallest != currS->data)
			{
				countS++;
				currS = currS->next;
				
			}
			
			
			Node *curr1 = head;
			
			while (curr1->next != NULL)
			{
				if(bigg >= curr1->data)
				{
					curr1 = curr1->next;
				}
				
				else if(bigg < curr1->data)
				{
					bigg = curr1->data;
					curr1 = curr1->next;
				}
			}
			
			Node *temp = head;
			while(bigg != temp->data){
				countB++;
				temp=temp->next;
				
			}
			
			curr->next = newNode;
			
			
			if(gate == true)
			{
				print(countS, countB);
			}
		}
			
			

};

int main()
{
	int n;
	bool x = false;
	LinkedList linkedlist;
	
	cout << "Enter your list: ";
	while(n != -1)
	{
		cin >> n;
		if (n == -1)
		{
			linkedlist.insertToEnd(n, true);
		}
		linkedlist.insertToEnd(n, x);
	}
	
	return 0;
}
