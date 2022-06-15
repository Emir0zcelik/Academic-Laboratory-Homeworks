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
        newNode ->next = NULL;
        return newNode;
    }
public:
    LinkedList():head(NULL) {}

	Node *addressOfHead(){
			return head;
	}
    void print() {
        Node *curr = head;
        while(curr != NULL) {
            cout<<curr->data<<"->";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }


    void insertToEnd(int data) {
        Node *newNode = createNode(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    
    int getSize() {
        int count = 0;
        Node *curr = head;
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }
        return count;
    }
};


int main()
{
	LinkedList linkedlist;
	int x, n;
	
	cout << "Enter starting number: ";
	cin >> x;
	
	while (x  != 1)
	{
		linkedlist.insertToEnd(x);
		if(x % 2 == 0)
		{
			x = x / 2;
		}
		
		else if(x % 2 == 1)
		{
			x = (x * 3) + 1;
		}
	}
	linkedlist.insertToEnd(1);
	cout << "List has been generated (" << linkedlist.getSize() << " integers):"<< endl;
	linkedlist.print();
	
	Node *curr = linkedlist.addressOfHead();
	Node *curr1 = linkedlist.addressOfHead();
	
	cout << "Enter search term:";
	cin >> n;
	
	int count = 0;
	while(curr->next != NULL)
	{
		count++;
		if(curr->data == n)
		{
			cout << n << " is found in node " << count << ". Numbers leading to " << n << " in the list are:" << endl;
			break;
		}

		curr = curr->next;
	}
	
	if(curr->data != n)
	{
		cout << n << " is not in the list." << endl;
		return 0;
	}
	
	for (int i = 0; i < count; i++)
	{
		cout << curr1->data << "->";
		curr1 = curr1->next;
	}
	cout << "NULL"<< endl;
	
}
