#include <iostream>

using namespace std;

class rectangle
{
	private:
		int length,breadth, area;
	
	public:
		
	int getLength()
	{
		return length;
	}
	void setLength(int length2)
	{
		length = length2;
	}
	int getBreadth(){
		return breadth;
	}
	void setBreadth(int breadth2){
		breadth = breadth2;
	}
	int getArea(){
		return area;
	}
	void setArea(int area2){
		area = area2;
	}
};

int main()
{
	int n, len, bread, peri, totalArea = 0;
	
	cout << "Enter the number of rectangle: ";
	cin >> n;
	
	rectangle x[n];
	
	for(int i = 0; i < n; i++)
	{
		cout << "Enter the length of " << i+1 << ". rectangle:";
		cin >> len;
		x[i].setLength(len);
		cout << "Enter the breadth of " << i+1 << ". rectangle:";
		cin >> bread;
		x[i].setBreadth(bread);
		
		x[i].setArea(len * bread); 
		
		totalArea += x[i].getArea();
		peri += (x[i].getBreadth() + x[i].getLength()) * 2;
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << "Area: " << x[i].getArea() <<endl;
	}
	
	cout <<"Total area: " << totalArea << "  Total Perimeter: " << peri <<endl;
	
}
