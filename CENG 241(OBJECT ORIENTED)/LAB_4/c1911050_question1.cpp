#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct COURSE {
	string code[20];
	double grade[20];
}; 

int main()
{
	vector<COURSE> x;
	COURSE y;
	double grade;
	double sum = 0.0;
	string code;
	char cnt = 'y';
	int i = 0;
	
	for(int k = 0; k < 20; k++)
	{
		y.grade[k] = 0;
	}
	
	while (cnt == 'Y' || cnt == 'y')
	{
		cout <<"Enter course code and grade: ";
		cin >> code >> grade;
		cout <<"Add new course? ";
		cin >> cnt;
		
		y.code[i] = code;
		y.grade[i] = grade;

		x.push_back(y);
		i++;
	}
	
	cout <<"List of entered " << i << " cources:" << endl;
	
	for (int j = 0; j < i; j++)
	{
		cout << "- " << y.code[j] << ", Grade: " << y.grade[j] << endl;
		sum += y.grade[j];
	}
	
	cout << "CGPA: " << sum /i;
}
