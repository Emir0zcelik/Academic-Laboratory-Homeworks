#include <iostream>

using namespace std;

int main ()
{
	int size;
	
	cout << "How many numbers letters are you going to enter? ";
	cin >> size;
	
	int n, sum {0}, i, k {0};
	
	char *x = new char[size], y;
	
	
	for(int i = 0; i < size; i++)
	{
		cout << "Enter letter and how mant times it will be repeated: ";
		cin >> y >> n;
		sum += n;
		
		while(k < sum)
		{
			x[k] = y;
			k++;
		}
	}
	
	for (i = 0; i < sum; i++)
	{
		cout << x[i];
	}
}
