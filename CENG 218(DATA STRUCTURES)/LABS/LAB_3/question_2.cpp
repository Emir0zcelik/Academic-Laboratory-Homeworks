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
};


int main() {

    LinkedList linkedlist1;
    LinkedList linkedlist2;
    LinkedList linkedlist3;
    cout << "Enter First List: ";
    int x ,n;
    while(n != -1)
	{
    	cin >> n;
    	linkedlist1.insertToEnd(n);
	}
	
	cout << "Enter Second List: ";
	
	while(x != -1)
	{
    	cin >> x;
		linkedlist2.insertToEnd(x);
	}
	
	Node *curr1 = linkedlist1.addressOfHead();
	Node *curr2 = linkedlist2.addressOfHead();
	
	while(curr1 != NULL && curr2 != NULL)
	{
		if(curr1->data < curr2->data){
			linkedlist3.insertToEnd(curr1->data);
			curr1 = curr1->next;
		}
		
		else{
			linkedlist3.insertToEnd(curr2->data);
			curr2 = curr2->next;
		}	
	}
	
	if(curr1 == NULL)
		{
			while(curr2->next != NULL)
			{
				linkedlist3.insertToEnd(curr2->data);
				curr2 = curr2->next;	
			}	
		}
		
	else if(curr2 == NULL)
	{
		while(curr1->next != NULL)
		{
			linkedlist3.insertToEnd(curr1->data);
			curr1 = curr1->next;	
		}	
	}
	linkedlist3.insertToEnd(curr1->data); // son datayı eklemeyi başaramadığım için manuel olarak ekledim
	
	linkedlist3.print();
    return 0;
}
