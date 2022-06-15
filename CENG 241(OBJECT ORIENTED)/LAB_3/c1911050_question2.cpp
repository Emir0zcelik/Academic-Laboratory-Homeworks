#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string str;
	string sub;
	int count = 0;
	
	cout << "Enter any string first :: ";
	getline(cin, str);
	
	cout << "Enter Substring u want to Search :: ";
	getline(cin, sub);
	
	int len1 = str.length();
	int len2 = sub.length();
	
	for(int i = 0; i < len1 + 1; i++)
	{
		if (count != len2)
		{
			if (str[i] == sub[count])
			{
				count++;
			}
		}	
		else
		{
			cout << "\n The substring [" << sub << "]  is present in given string at position [" << i - 1 << "]";
			break;	
		}
	}
	
	return 0;
}

