#include <iostream>

using namespace std;

int main ()
{
	int arr[10];
	int n;
	
	cout << "Enter bar heights: ";
	
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	
	
	//column
	for (int i = 0; i < 10; i++)
	{
		//row
		for (int j = 0; j < 10; j++)
		{
			if(arr[j] >= i+1)
			{
				cout << "#";
			}
			else 
			{
				cout << " ";
			}
		}	
		cout << "\n";
	}
	
}

