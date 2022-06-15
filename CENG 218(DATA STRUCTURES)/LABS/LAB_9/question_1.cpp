#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define SIZE 31
#define PARENT(i) ceil(i/2.0)-1
#define LCHILD(i) 2*i+1
#define RCHILD(i) 2*i+2

struct Student{
	int idNumber;
	string name;
	int grade;
};

class MinHeap{
	private:
		struct Student data[SIZE];
		int count;
	public:
		MinHeap():count(0) {}
		
		bool isEmpty(){
			return count == 0;
		}
		
		bool isFull(){
			return count == SIZE;
		}
		
		void insert (int id, string name, int grade){
			if(isFull())
				return;
				
			data[count].idNumber = id;
			data[count].name = name;
			data[count].grade = grade;
			heapUp(count);
			count++;
		}
		
		void heapUp(int ind){
			if(ind == 0)
				return;
				
			int pIndex = PARENT(ind);
			
			if(data[pIndex].grade > data[ind].grade){
				
				int tempGrade = data[pIndex].grade;
				string tempName = data[pIndex].name;
				int tempId = data[pIndex].idNumber;
				
				data[pIndex].grade = data[ind].grade;
				data[pIndex].name = data[ind].name;
				data[pIndex].idNumber = data[ind].idNumber;
				
				data[ind].grade = tempGrade;
				data[ind].name = tempName;
				data[ind].idNumber = tempId;
				
				heapUp(pIndex);
			}	
		}
		
		void heapDown(int ind){
			int lchild = LCHILD(ind);
			int rchild = RCHILD(ind);
			if(ind == count-1 || LCHILD(ind) > count)
				return;
			int minChildInd;
			
			if(rchild < count){
            	minChildInd = data[lchild].grade < data[rchild].grade ? lchild:rchild;
        	}
			else{
				minChildInd = lchild;
			}
			
			if (data[minChildInd].grade < data[ind].grade){
				int tempGrade = data[ind].grade;
				string tempName = data[ind].name;
				int tempId = data[ind].idNumber;
				
				data[ind].grade = data[minChildInd].grade;
				data[ind].name = data[minChildInd].name;
				data[ind].idNumber = data[minChildInd].idNumber;
				
				data[minChildInd].grade = tempGrade;
				data[minChildInd].name = tempName;
				data[minChildInd].idNumber = tempId;
				
				heapDown(minChildInd);
			}
		}
		
		struct Student extractMin(){
			struct Student dt = data[0];
        	data[0] = data[--count];
        	heapDown(0);
       		return dt;
		}
};

int main()
{
	MinHeap heap;
	fstream file;
	string line;
	int id, grade, i = 0;
	string name;
	file.open("218l9.txt");

	while(!file.eof())
	{
		file >> id;
        file >> name;
        file >> grade;
        heap.insert(id,name,grade);
	}
	
	struct Student student;
	
	
	while(!heap.isEmpty()){
		student = heap.extractMin();
		cout << i << " - " << student.idNumber << " " << student.name << " " << student.grade << endl;
		i++;
	}
	return 0;
}
