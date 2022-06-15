#include <iostream>

using namespace std;

struct Classroom
{
	char cname;
	int n;
	int learn;	
};

int main ()
{
	struct Classroom r[5];
	int percantage[5];
	int total;
		
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter information for " << (i+1) <<". class:\n";
		cout << "Letter: ";
		cin >> r[i].cname;
		cout << "Total number of students: ";
		cin >> r[i].n;
		cout << "Number of students who have learned to read: ";
		cin >> r[i].learn;
		cout << "\n";
	}
	
	cout << "Percantage of students who have learned to read:\n";
	
	for (int i = 0; i < 5; i++)
	{
		percantage[i] = (r[i].learn / r[i].n) % 100;
	}
	
	total = (percantage[1] + percantage[2] + percantage[3] + percantage[4] + percantage[0]) / 5;
	
	for (int i = 0; i < 5; i++)
	{
		
		cout << "Classroom 1-" << r[i].cname << ": " << percantage[i] << "% \n";
	}
	cout << "School total: " << total << "%";
}

