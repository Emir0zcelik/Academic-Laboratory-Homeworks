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
		
		int sumOfNodes(TNODE *root){
			if(root == NULL)
			{
				return 0;
			}
			
			int sum = root->data;
			return sumOfNodes(root->left) + sumOfNodes(root->right) + sum;
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
		
		int sumOfNodes()
		{
			return sumOfNodes(root);
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
	int count = bst.sumOfNodes();
	cout << "The sum of the all nodes: " << count << endl;
}
