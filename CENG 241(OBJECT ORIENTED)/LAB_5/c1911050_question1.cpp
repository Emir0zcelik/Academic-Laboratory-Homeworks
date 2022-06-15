#include <iostream>

using namespace std;

class VideoGames
{
	private:
       string type;
       string name;
       double price;
       bool buy;
	
	public:
		string getType()
		{
			return type;
		}
		
		void setType(string Type2)
		{
			type = Type2;
		}
		string getName()
		{
			return name;
		}
		
		void setName(string Name2)
		{
			name = Name2;
		}
		
		double getPrice()
		{
			return price;
		}
		
		void setPrice(double Price2)
		{
			price = Price2;
		}
		
		bool getBuy()
		{
			return buy;
		}
		
		void setBuy(bool Buy2)
		{
			buy = Buy2;
		}	
};

int main ()
{
	int n;
	string str;
	double discount, op;
	
	
	cout << "Enter the number of video games you want to buy:";
	cin >> n;
	
	double newPrice[n];
	VideoGames t[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Game Type: ";
		cin >> str;
		t[i].setType(str);
		
		cout << "Enter Game Name:";
		cin >> str;
		t[i].setName(str);
		
		cout << "Enter Game Price:";
		cin >> op;
		t[i].setPrice(op);
		
		cout << "\n";
		
		if(t[i].getType() == "Action")
       {
           discount = 0.1;
       }
       else if(t[i].getType() == "Strategy")
       {
           discount = 0.20;
       }
       else if(t[i].getType() == "Sport")
       {
           discount = 0.30;
       }
       else if(t[i].getType() == "Adventure")
       {
           discount = 0.25;
       }
       
       newPrice[i] = t[i].getPrice() - t[i].getPrice() * discount;
       
       if(newPrice[i] <= 150)
       {
       		t[i].setBuy(1);
	   }
	   else
	   {
	   	t[i].setBuy(0);
	   }
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << "Game " << i+1 << ": " << endl;
		cout << "Name: " << t[i].getName() << endl;
		cout << "Type: " << t[i].getType() << endl;
		cout << "Price: " << t[i].getPrice() << " Discounted Price: " << newPrice[i] << endl;
		cout << "Buy: " << t[i].getBuy() << endl; 
	}
}
