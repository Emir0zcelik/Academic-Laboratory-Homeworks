#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Exam{
	private:
		string type;
		string date;
		string time;
	public:
		Exam()
		{
			type = " ";
			date = " ";
			time = " ";
		}
		
		void set_type(string type)
		{
			this->type = type;
		}
		
		void set_date(string date)
		{
			this->date = date;
		}
		
		void set_time(string time)
		{
			this->time = time;
		}
		
		string get_type()
		{
			return type;
		}
		
		string get_date()
		{
			return date;
		}
		
		string get_time()
		{
			return time;
		}
};

class Course{
	private:
		int select;
		string code;
		vector <string> codes;
		vector <Exam> exams;
	public:
		Course()
		{
			code = " ";
			select = 0;
		}
		
		void set_select(int select)
		{
			this->select = select;
		}
		
		int get_select()
		{
			return select;
		}
		
		void set_code(string code)
		{
			codes.push_back(code);
		}
		
		void add(Exam x)
		{
			exams.push_back(x);
		}
		
		void printWithNumbers()
		{
			for(int i = 0; i < codes.size(); i++)
			{
				cout << i+1 << ". " << codes[i] << endl; 
			}
		}
		
		void printExams()
		{
			if(codes.size() == 0)
			{
				cout << "(none)" << endl;
			}
			 
			for (int i = 0; i < codes.size(); i++)
			{
				cout << codes[i];
				if(!exams.empty())
				{
					for (int j = i; j < exams.size(); j++)
					{
						cout << " " << exams[j].get_type() << " " << exams[j].get_date() << " " << exams[j].get_time();
						break;
					}
				}
				cout << endl;
			}
		}
		
		void deleteCourse()
		{
			for(int i = 0; i < codes.size(); i++)
			{				
				if(select - 1 == i)
				{
					for(int j = 0; j < codes.size() - select; j++)
					{
						codes[i] = codes[i + 1];
					}	
				}
			}			
		}
		
		void deleteExams()
		{
			exams[select - 1].set_type(""); 
			exams[select - 1].set_date(""); 
			exams[select - 1].set_time("");
		}
		
		
};

class ExamTable{
	private:
		vector <Course> courses;
	public:
		
		void add(Course y)
		{
			courses.push_back(y);
		}
		/*
		void print()
		{
			sort();
			write();
			read();
		}
		
		void read()
		{
			int counter = 0;
			ifstream file;

			file.open("exams.txt");
			
			courses.clear();
			string code, type, date, time;
			
			while(!file.eof())
			{
				file >> code >> type >> date >> time;
				cout << code << " " << type << " " << date << " " << time << endl;
				
				counter++;

				if(count == courses.size())
				{
					break;
				}	
			}	
			file.close();
		}
		
		void write()
		{
			ofstream WriteFile("exams.txt");
			
			for (int i = 0; i < courses.size(); i++)
			{
				
			}
		}
		
		void sort()
		{
			
		}
		*/
		
};

void mainMenu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1. Display table" << endl;
	cout << "2. Add new course" << endl;
	cout << "3. Delete existing course" << endl;
	cout << "4. Add exam to existing course" << endl;
	cout << "5. Delete existing exam" << endl;
	cout << "6. Exit" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main()
{
	Exam exam;
	Course course;
	ExamTable examtable;
	int choice;
	
	do
	{
		mainMenu();
		cout << "Your choice:";
		cin >> choice;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				 				
		if(choice == 1)
		{
			cout << "Course     Type     Date     Time" << endl;
			cout << "---------------------------------" << endl;
			course.printExams();
		}
		
		else if(choice == 2)
		{
			string coursecode;
			cout << "Enter course code: ";
			cin >> coursecode;
			course.set_code(coursecode);
		}
		
		else if(choice == 3)
		{
			int deleteCourse;
			cout << "Enter course code: ";
			cin >> deleteCourse;
			course.set_select(deleteCourse);
			course.deleteCourse();
		}
		
		else if(choice == 4)
		{
			int select;
			string type, date, time;
			cout << "Available courses:" << endl;
			course.printWithNumbers();
			cout << "Which course?";
			cin >> select;
			course.set_select(select);
			cout << "Enter exam type, date and time:" << endl;
			cin >> type >> date >> time;
			exam.set_type(type);
			exam.set_date(date);
			exam.set_time(time);
			course.add(exam);
			
		}
		
		else if(choice == 5)
		{
			int deleteExam;
			course.printWithNumbers();
			cout << "Enter the course number to delete exam:" << endl;
			cin >> deleteExam;
			course.set_select(deleteExam);
			course.deleteExams();
			
		}
	}while(choice != 6);
	
	cout << "Bye!" << endl;
	return 0;
}
