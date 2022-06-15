#include <iostream>
#include <vector>

using namespace std;

class List{
	private:
	string name;
	vector <string> names;
		
	public:
		List()
		{
			name = " ";
		}
		
		List(string name)
		{
			this->name = name;
		}
		
		
		vector <string> operator+=(string &name)
		{
			names.push_back(name);
			return names;
		}
		
		void print()
		{
			for(int i = 0; i < names.size(); i++)
			{
				for (int j = i; j < names.size(); j++)
				{
					if (names.at(i) > names.at(j))
					{
						string temp;
						
						temp = names.at(i);
						names.at(i) = names.at(j);
						names.at(j) = temp;
					}
				}
			}
			
			for (int i = 0; i < names.size(); i++)
			{
				cout << names.at(i) << endl;
			}
		}
		
		
		
};

int main()
{
	List names;
	string name;
	cout << "Please enter names: " << endl;
	
	while(name != "END"){
		cin >> name;
		
		if(name == "END")
		{
			break;
		}
		names += name;
		
	}
	names.print();
	
	return 0;
}
