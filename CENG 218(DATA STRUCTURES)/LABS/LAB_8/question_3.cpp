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
		
		int numberOfSingleChild(TNODE *root){
			if(root == NULL)
			{
				return 0;
			}
			
			else if(root->left != NULL && root->right == NULL)
			{
				return numberOfSingleChild(root->left) + 1;
			}
			else if(root->left == NULL && root->right != NULL)
			{
				return	numberOfSingleChild(root->right) + 1;
			}
			else{
				return numberOfSingleChild(root->left) + numberOfSingleChild(root->right);
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
		
		int numberOfSingleChild()
		{
			return numberOfSingleChild(root);
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
		if(n < 0)
		{
			break;
		}
		bst.insert(n);
	}
	
	int count = bst.numberOfSingleChild();
	
	cout << count;
}
