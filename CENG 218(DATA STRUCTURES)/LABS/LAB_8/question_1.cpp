#include <iostream>

using namespace std;

typedef struct TNode{
	int data;
	struct TNode *left;
	struct TNode *right;
}TNODE;

class BST{
	private:
		TNODE *root;
		TNODE * createNode(int data){
			TNODE *newNode = new TNODE;
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}
		
		TNODE *insert(TNODE *root, int data){
			if(root == NULL)
			{
				return createNode(data);
			}
			
			else if(root->data > data)
			{
				root->left = insert(root->left, data);
			}
			
			else if(root->data < data)
			{
				root->right = insert(root->right, data);
			}
			return root;
		}
		
		int numberOfEven(TNODE *root){
			int count;
			if(root == NULL)
			{
				return 0;
			}
			
			else if(root->data %2 == 0)
			{
				return 1 + numberOfEven(root->left) + numberOfEven(root->right);
			}
			
			else{
				return numberOfEven(root->left) + numberOfEven(root->right);
			}
					
		}
		
	public:
		BST()
		{
			root = NULL;
		}
		
		void insert(int data)
		{
			root = insert(root, data);		
		}
		
		int numberOfEven()
		{
			return numberOfEven(root);
		}
};

int main()
{
	BST bst;
	int n;
	cout << "Please enter the numbers you want to add in tree:" << endl;
	while(n>=0)
	{
		cin >> n;
		bst.insert(n);
	}
	int count = bst.numberOfEven();
	cout << "The number of even nodes:" << count << endl;
}
