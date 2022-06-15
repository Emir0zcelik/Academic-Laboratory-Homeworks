#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
	fstream file;
	string info[20];
	string name;
	char cnt = 'y';
	int i = 0;
	int counter = 1;
	cout << "Enter file name: ";
	cin >> name;
	
	file.open(name.c_str(), ios::out);
	cout << "Enter information to store..\n";
	while (cnt == 'y')
	{
		cin >> info[i];
		counter++;
		cout << "Want to enter more ? (y/n).. ";
		cin >> cnt;
		i++;
	}
	
	cout << "The information succesfully stored in the file..!!\n";
	
	cout << "Want to see ? (y/n)..";
	cin >> cnt;
	
	if (cnt == 'y')
	{
		for (int j = 0; j < counter; j++)
		{
			cout << info[j] << "\n";
		}
	}
	
	else
	{
		return 0;
	}
}
