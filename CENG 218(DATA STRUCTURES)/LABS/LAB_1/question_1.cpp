#include <iostream>
#include <vector>

using namespace std;

//Base Student Class
class Student {
	protected:
		int id;
		string name;
	public:
		Student()
		{
			id = 0;
			name = " ";
		}
		
		Student(int id, string name) 
		{
			this -> id = id;
			this -> name = name;
		}
		
		void set_id (int id) 
		{
			this->id = id;
		}
		
		void set_name (string name)
		{
			this->name = name;
		}
		
		int get_id ()
		{
			return id;
		}
		
		string get_name()
		{
			return name;
		}
		
		void print() 
		{
			cout << id << " " << name << endl;
		}
};

//Derived Class For Student

class GradStudent : public Student {
	private:
		bool thesis;
	public:
		GradStudent()
		{
			id = 0;
			name = " ";
			thesis = false;
		}
		
		GradStudent(int id, string name, bool thesis) : Student (id, name) 
		{
			this->id = id;
			this->name = name;
			this->thesis = thesis;
		}
		
		void set_thesis(bool thesis)
		{
			this->thesis = thesis;
		}
		
		bool get_thesis ()
		{
			return thesis;
		}
		
		bool withThesis()
		{
			return thesis;
		}
};

//Base Course Class

class Course {
	protected:
		string code;
	public:
		Course()
		{
			code = " ";
		}
		
		Course(string code)
		{
			this->code = code;
		}
		
		void set_code(string code)
		{
			this->code = code;
		}
		
		string get_code()
		{
			return code;
		}
};

//First Derived Class For Course

class UndergradCourse : public Course {
	private:
		vector <Student> students;
	public:
		UndergradCourse()
		{
			code = " ";
		}
		
		UndergradCourse(string code) : Course (code)
		{
			this->code = code;
		}
		
		void enroll (Student student)
		{
			students.push_back(student);
		}
		
		void listStudents()
		{
			for (int i = 0; i < students.size(); i++)
			{
				cout << i + 1 << " ";
				students[i].print();
			}
		}
		
};

//Second Derived Class For Course

class GradCourse : public Course {
	private:
		vector <GradStudent> students;
	public:
		GradCourse()
		{
			code = " ";
		}
		
		GradCourse(string code) : Course (code) 
		{
			this->code = code;
		}
		
		void enroll(GradStudent student)
		{
			students.push_back(student);
		}
		
		void listStudents()
		{
			for (int i = 0; i < students.size(); i++)
			{
				cout << i + 1 << " ";
				students[i].print();
				
				if (students[i].withThesis() == true)
				{
					cout << i + 1 << " " << students[i].get_id() << " - " << students[i].get_name() << " (with thesis)" << endl;
				}
				else
				{
					cout << i + 1 << " " << students[i].get_id() << " - " << students[i].get_name() << endl;
				}
			}
		}
};

void MainMenu()
{
	cout << "Welcome to registration system!" << endl;
	cout << "1. Register new undergraduate student" << endl;
	cout << "2. Register new graduate student" << endl;
	cout << "3. Display student lists" << endl;
	cout << "4. Exit" << endl;
}

int main()
{
	vector <Student> students;
    vector <GradStudent> gstudents;
    UndergradCourse ucourse;
    GradCourse gcourse;
	int n, id;
	string name, select;
	bool thesis;
	
	do
	{
		MainMenu();
		cout << "Your choice: ";
		cin >>	n;
		
		if (n == 1)
		{
			cout << "Enter student ID and name: ";
			cin >> id >> name;
			
			Student x(id, name);
			students.push_back(x);
			ucourse.enroll(x);
		}
		
		else if (n == 2)
		{
			cout << "Enter student ID and name: ";
			cin >> id >> name;
			cout << "Enroll"<< name <<"to thesis?";
			cin >> select;
			
			if (select == "yes")
			{
				thesis = true;
			}
			else if (select == "no")
			{
				thesis = false;
			}
			
			Student x(id, name);
			students.push_back(x);
			GradStudent xgstudents(id, name, thesis);
			gcourse.enroll(xgstudents);
			
		}
		
		else if (n == 3)
		{
			ucourse.set_code("ceng 105:");
			cout << ucourse.get_code() << endl;
			ucourse.listStudents();
			
			ucourse.set_code("ceng 111:");
			cout << ucourse.get_code() << endl;
			ucourse.listStudents();
			
			ucourse.set_code("ceng 501:");
			cout << gcourse.get_code() << endl;
			gcourse.listStudents();
			
			ucourse.set_code("ceng 502:");
			cout << gcourse.get_code() << endl;
			gcourse.listStudents();
		}
		
	} while (n != 4);
	
	cout << "Bye!" << endl;
	
	return 0;
}






