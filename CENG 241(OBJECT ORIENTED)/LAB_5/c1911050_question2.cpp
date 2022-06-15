#include <iostream>

using namespace std;

class Student
{
	private:
		int id;
		string name;
		int year;
		float gpa;
		float exam;
	
	public:
		int getId()
		{
			return id;
		}
		
		void setId(int id2)
		{
			id = id2;
		}
		
		string getName()
		{
			return name;
		}
		
		void setName(string name2)
		{
			name = name2;
		}
		
		int getYear()
		{
			return year;
		}
		
		void setYear(int year2)
		{
			year = year2;
		}
		
		float getGpa()
		{
			return gpa;
		}
		
		void setGpa(double gpa2)
		{
			gpa = gpa2;
		}
		
		float getExam()
		{
			return exam;
		}
		
		void setExam(float exam2)
		{
			exam = exam2;
		}	
};

int main ()
{
	int n, id, year, emp;
	string str;
	float exam, gpa;
	
	
	cout << "Enter the number of student:";
	cin >> n;
	
	float formula[n];
	Student x[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter information for student id:";
		cin >> id;
		x[i].setId(id);
		
		cout << "Enter information for student name:";
		cin >> str;
		x[i].setName(str);
		
		cout << "Enter information for student year:";
		cin >> year;
		x[i].setYear(year);
		
		cout << "Enter information for student gpa:";
		cin >> gpa;
		x[i].setGpa(gpa);
		
		cout << "Enter information for student exam:";
		cin >> exam;
		x[i].setExam(exam);
	
		formula[i] = (x[i].getExam() * x[i].getGpa()) / 2;
	}
	
	cout << "Results -> ";
	
	for (int i = 0; i < n; i++)
	{
		cout << x[i].getName() << ":" << formula[i] << "," ;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(formula[i] > formula[i+1])
		{
			emp = i;
		}
	}
	
	cout << "\n" << x[emp].getName() << " has just employeed .";
	
}
