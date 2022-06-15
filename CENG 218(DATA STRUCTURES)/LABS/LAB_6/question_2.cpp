#include <iostream>

using namespace std;

#define MAX 50

typedef struct node{
	int data;
	struct node *next;
}Node;

bool isMember(Node *mem ,int x);

class LinkedList{
	private:
		Node *head;
		int size;
		Node* createNode(int data){
			Node *newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;
			return newNode;
		}
	public:
		LinkedList(): head(NULL), size(0) {}
		
		bool isEmpty(){
			return head == NULL;
		}
		
		void print()
		{
			Node* curr = head;
			
			if(isEmpty())
			{
				return;
			}
			
			while(curr != NULL)
			{
				cout << curr->data << "->";
				curr = curr->next;
			}
			cout << "NULL" << endl;
		}
		
		void insertToEnd(int data)
		{
			Node *newNode = createNode(data);
			
			if(head == NULL)
			{
				head = newNode;
				return;
			}
			
			Node *curr = head;
			while(curr->next != NULL)
			{
				curr = curr->next;
			}
			
			curr->next = newNode;
			size++;
		}
		
		int getSize()
		{
			int count = 0;
			Node *curr = head;
			while(curr!= NULL)
			{
				curr = curr->next;
				count++;
			}
			return count;
		}
		
		bool search(int x)
		{
			isMember(head, x);
		}
};

bool isMember(Node *mem ,int x)
{
	if(mem->data == x)
	{
		cout << x << " is available in the linked list." << endl;
		return true;
	}
	else if(mem->next == NULL && mem->data != x)
	{
		cout << x << " is not available in the linked list." << endl; 	
		return false;
	}
	isMember(mem->next, x);
}

int main()
{
	LinkedList list;
	int n, search;
	
	cout << "Fill your linked list: ";
	do
	{
		cin >> n;
		if (n == -1)
		{
			break;
		}
		list.insertToEnd(n);
	}while(n != -1);
	
	list.print();
	
	cout << "Enter search term: ";
	cin >> search;
	list.search(search);
	
	return 0;	
}


