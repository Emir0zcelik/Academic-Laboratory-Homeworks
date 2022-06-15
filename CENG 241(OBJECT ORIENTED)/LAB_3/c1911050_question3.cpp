#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string str;
	
	int vow_count = 0;
	int con_count = 0;
	int dig_count = 0;
	int space_count = 0;
	
	cout << "Enter a line of string: ";
	getline(cin, str);
	
	int len = str.length();
	
	for (int i = 0; i < len + 1; i++)
	{
		//Vowels (a e i o u A E I O U)
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			vow_count++;
		}
		
		//Digits (0 1 2 3 4 5 6 7 8 9)
		else if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
			dig_count++;
		}
		
		//White Space (" ")
		else if (str[i] == ' ')
		{
			space_count++;
		}
	}
	// Consonants (The equation will be work if the user do not enter the special characters)
	con_count += len - (vow_count + dig_count + space_count);
	
	cout << "Vowels: " << vow_count << "\n" << "Consonants: " << con_count << "\n" << "Digits: " << dig_count << "\n" << "White spaces: " << space_count;
}
