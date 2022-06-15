#include <iostream>
#include <string>
#define MAX 50
class GameLibrary{
	private:
		std::string names[MAX];
		int prices[MAX];
		int discountPercantages[MAX];
		int dicountedPrices[MAX];
		int size;
	public:
		GameLibrary()
		{
			size = 0;
		}
		
		void sortByName()
		{
			std::string temp;
			int temp1;
			int temp2;
			int temp3;
			
			for(int i = 0; i < size; i++)
			{
				for(int j = i + 1; j < size; j++)
				{
					if(names[i] < names[j])
					{
						temp = names[i];
						names[i] = names[j];
						names[j] = temp;
						
						temp1 = prices[i];
						prices[i] = prices[j];
						prices[j] = temp1;
						
						temp2 = discountPercantages[i];
						discountPercantages[i] = discountPercantages[j];
						discountPercantages[j] = temp2;
						
						temp3 = dicountedPrices[i];
						dicountedPrices[i] = dicountedPrices[j];
						dicountedPrices[j] = temp3;
					}
				}
			}
		}
		
		void  sortByPrice()
		{
			int temp;
			std::string temp1;
			int temp2;
			int temp3;
			
			for(int i = 0; i < size; i++)
			{
				for(int j = i + 1; j < size; j++)
				{
					if(prices[i] < prices[j])
					{
						temp = prices[i];
						prices[i] = prices[j];
						prices[j] = temp;
						
						temp1 = names[i];
						names[i] = names[j];
						names[j] = temp1;
						
						temp2 = discountPercantages[i];
						discountPercantages[i] = discountPercantages[j];
						discountPercantages[j] = temp2;
						
						temp3 = dicountedPrices[i];
						dicountedPrices[i] = dicountedPrices[j];
						dicountedPrices[j] = temp3;
					}
				}
			}
		}
		
		void sortByDiscount()
		{
			int temp;
			std::string temp1;
			int temp2;
			int temp3;
			
			for(int i = 0; i < size; i++)
			{
				for(int j = i + 1; j < size; j++)
				{
					if(discountPercantages[i] > discountPercantages[j])
					{
						temp = discountPercantages[i];
						discountPercantages[i] = discountPercantages[j];
						discountPercantages[j] = temp;
						
						temp1 = names[i];
						names[i] = names[j];
						names[j] = temp1;
						
						temp2 = prices[i];
						prices[i] = prices[j];
						prices[j] = temp2;
						
						temp3 = dicountedPrices[i];
						dicountedPrices[i] = dicountedPrices[j];
						dicountedPrices[j] = temp3;
					}
				}
			}
		}
		
		void sortByDiscountedPrice()
		{
			int temp;
			std::string temp1;
			int temp2;
			int temp3;
			
			for(int i = 0; i < size; i++)
			{
				for(int j = i + 1; j < size; j++)
				{
					if(dicountedPrices[i] < dicountedPrices[j])
					{
						temp = discountPercantages[i];
						discountPercantages[i] = discountPercantages[j];
						discountPercantages[j] = temp;
						
						temp1 = names[i];
						names[i] = names[j];
						names[j] = temp1;
						
						temp2 = prices[i];
						prices[i] = prices[j];
						prices[j] = temp2;
						
						temp3 = dicountedPrices[i];
						dicountedPrices[i] = dicountedPrices[j];
						dicountedPrices[j] = temp3;
						
						
					}
				}
			}
		}
		
		void list()
		{
			std::cout << "Name		Price		Percantage		Discounted Price" << std::endl;
			std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
			for(int i = 0; i < size; i++)
			{
				std::cout << names[i] << "		" << prices[i] << " TL		" << discountPercantages[i]  << "%		" << dicountedPrices[i] << " TL" << std::endl;
			}
		}
		
		void remove(std::string name)
		{
			for(int i = 0; i < size; i++)
			{
				names[i] = names[i + 1];
				prices[i] = prices[i + 1];
				discountPercantages[i] = discountPercantages[i + 1];
				dicountedPrices[i] = dicountedPrices[i + 1];
			}
		}
		
		void insert(std::string name, int price, int discountPercantage)
		{
			names[size] = name;
			prices[size] = price;
			discountPercantages[size] = discountPercantage;
			dicountedPrices[size] = price - (price * discountPercantage) / 100;
			size++;
		}
};

void mainMenu()
{
	std::cout << "1. Display Library" << std::endl;
	std::cout << "2. Add Game" << std::endl;
	std::cout << "3. Remove Game" << std::endl;
	std::cout << "4. Sort Library by game names" << std::endl;
	std::cout << "5. Sort Library by game prices" << std::endl;
	std::cout << "6. Sort Library by game discount percantages" << std::endl;
	std::cout << "7. Sort Library by dicounted game prices" << std::endl;
	std::cout << "8. Exit" << std::endl;
}

int main()
{
	GameLibrary game;
	int choice;
	
	while(choice != 8)
	{
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		mainMenu();
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		std::cout << "Your choice:";
		std::cin >> choice;
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		
		if(choice == 1)
		{
			game.list();	
		}
		
		else if(choice == 2)
		{
			std::string name;
			int price, percantage;	
			std::cout << "Enter game details: ";
			std::cin >> name >> price >> percantage;
			game.insert(name, price, percantage);
		}
		
		else if(choice == 3)
		{
			std::cout << "Enter the name of the game which you want to delete: ";
			std::string name;
			std::cin >> name;
			game.remove(name);
		}
		
		else if(choice == 4)
		{
			game.sortByName();
		}
		
		else if(choice == 5)
		{
			game.sortByPrice();
		}
		
		else if(choice == 6)
		{
			game.sortByDiscountedPrice();
		}
		
		else if(choice == 7)
		{
			game.sortByDiscountedPrice();
		}		
	}
	
	std::cout << "Bye!!" << std::endl;
}
