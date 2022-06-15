#include <iostream>

using namespace std;

int main ()
{
	char letter[26];
	int  count = 1;
	printf("Enter your letters: ");
	
	for (int i = 0; i < 26; i++)
	{
		cin >> letter[i];
	}
		
	cout << "Result: ";
	
	for (int i = 0; i < 26; i++)
	{	
		if (letter [i] == letter[i+1])
		{
			count++;
		}
			
		else
		{
			cout << count << " ";
			count =1;
		}	
	}
}

