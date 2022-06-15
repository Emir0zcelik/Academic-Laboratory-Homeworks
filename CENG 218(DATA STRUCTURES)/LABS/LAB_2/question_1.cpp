#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Province{
	private:
		string name;
		int population;
	public:
		
		Province()
		{
			name = " ";
			population = 0;
		}
		
		Province (string name, int population)
		{
			this->name = name;
			this->population = population;
		}
		
		void set_name(string name)
		{
			this->name = name;
		}
		
		void set_population(int population)
		{
			this->population = population;
		}
		
		string get_name()
		{
			return name;
		}
		
		int get_population()
		{
			return population;
		}
};

int main()
{
	vector<Province> province;
	int pop;
	string name, x;
	int count = 82;
	fstream myFile;
	
	myFile.open("provinces.txt");
	
	if(!myFile)
	{
		cout << "File not created! " << endl;
	}
	
	
	
	else 
	{
		
		cout << "Count:" << count << endl;
	
		cout << "File created succesfully!" << endl;
		
		for (int i = 0; i < count; i++)
		{
		myFile >> name >> pop;
		
		Province x (name, pop);
		
		province.push_back(x);
		}	
		
		for(int i = 0; i < count; i++)
		{
			for (int j = i; j < count; j++)
			{
				
				if(province[i].get_population() > province[j].get_population())
				{
					int temp;
					string temps;
					
					temps = province[i].get_name();
					temp = province[i].get_population();
					
					province[i].set_name(province[j].get_name());
					province[i].set_population(province[j].get_population());
					
					province[j].set_name(temps);
					province[j].set_population(temp);
				}
				
			}
		}
		for (int i = 0; i < count; i++)
		{
			cout << province[i].get_name() << " " << province[i].get_population() << endl;
		}
		
	}
	return 0;
}
