#include <iostream>

using namespace std;

class DistanceUnit{
	protected:
		float value;
	
	public:
		
		DisctanceUnit(){
			value = 0;
		}
		
		void operator ++ (int)
		{
			value++;
		}
		
		void operator -- (int)
		{
			value--;
		}
		
		void operator += (int temp)
		{
			value += temp;
		}
		
		void operator -= (int temp)
		{
			value -= temp;
		}
		
		void set_value(float value)
		{
			this->value = value;
		}
		
		float get_value()
		{
			return value;
		}
};

class toFeet : public DistanceUnit {
	public:
		
		float changefeet()
		{
			float temp;

			temp = value * 3.2;
			return temp;
		}
		
		void set_feet(float value)
		{
			this->value = value;
		}
		
		float get_feet()
		{
			return value;
		}
};

class toMeter : public DistanceUnit{
	public:
		
		float changemeter()
		{
			float temp1;
			
			temp1 = 0.32 * value;
			return temp1;
		}
		
		void set_meter(float value)
		{
			this->value = value;
		}
		
		float get_meter()
		{
			return value;
		}
};

int main()
{
	toFeet a;
	toMeter b;
	
	int choice = 0;
	float n = 0;
	
	cout << "1.Set distance to feet" << endl;
	cout << "2.Set distance to meter" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	if (choice = 1)
	{
		
		cout << "Distance: 0 feet." << endl;
		cout << "1.Move 1 foot forwards" << endl;
		cout << "2.Move 1 foot backwards" << endl;
		cout << "3.Move n foot forwards" << endl;
		cout << "4.Move n foot backwards" << endl;
		cout << "5.Convert to meters" << endl;
		cout << "6.Exit" << endl;
		
		cout << "Your choice: ";
		cin >> n;
			
		while (n != 6)
		{
			if (n == 1)
			{
				b++;
			}
			
			else if(n == 2)
			{
				b--;
			}
			
			else if(n == 3)
			{
				int i;
				cout << "Enter n: ";
				cin >> i;
				
				b += i;
			}
			
			else if(n == 4)
			{
				int x;
				cout << "Enter n: ";
				cin >> x;
				
				b -= x;
			}
			
			else if(n == 5)
			{
				cout << b.get_meter() << " feet: " << b.changemeter() << " meters." << endl;
			}
			
			cout << "Distance: " << b.get_meter() << " feet." << endl;
			cout << "1.Move 1 foot forwards" << endl;
			cout << "2.Move 1 foot backwards" << endl;
			cout << "3.Move n foot forwards" << endl;
			cout << "4.Move n foot backwards" << endl;
			cout << "5.Convert to meters" << endl;
			cout << "6.Exit" << endl;
			
			cout << "Your choice: ";
			cin >> n;
		}
		
		cout << "Bye!" << endl;
	}
	
	else if (choice = 2)
	{
		
		cout << "Distance: 0 feet." << endl;
		cout << "1.Move 1 meter forwards" << endl;
		cout << "2.Move 1 meter backwards" << endl;
		cout << "3.Move n meter forwards" << endl;
		cout << "4.Move n meter backwards" << endl;
		cout << "5.Convert to feet" << endl;
		cout << "6.Exit" << endl;
		
		cout << "Your choice: ";
		cin >> n;
		
		while (n != 6)
		{
			if (n == 1)
			{
				a++;
			}
			
			else if(n == 2)
			{
				a--;
			}
			
			else if(n == 3)
			{
				int i;
				cout << "Enter n: ";
				cin >> i;
				
				a += i;
			}
			
			else if(n == 4)
			{
				int x;
				cout << "Enter n: ";
				cin >> x;
				
				a -= x;
			}
			
			else if(n == 5)
			{
				cout << a.get_feet() << " meter: " << a.changefeet() << " feets." << endl;
			}
			
			cout << "Distance: " << a.get_feet() << " feet." << endl;
			cout << "1.Move 1 meter forwards" << endl;
			cout << "2.Move 1 meter backwards" << endl;
			cout << "3.Move n meter forwards" << endl;
			cout << "4.Move n meter backwards" << endl;
			cout << "5.Convert to feet" << endl;
			cout << "6.Exit" << endl;
			
			cout << "Your choice: ";
			cin >> n;
		}
		
		cout << "Bye!" << endl;
	}
	
	return 0;
}
