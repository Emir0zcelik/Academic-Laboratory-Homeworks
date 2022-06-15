#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 5

class Queue {
private:
    int items[MAX];
    int front;
    int rear;
    int live;
    int n;
   

public:
    Queue():front(0),rear(-1), live(5), n(0) {}
	
    bool isEmpty() {
        return front>rear;
    }

    bool isFull(){
        return rear == MAX-1;
    }

    bool enqueue(int data) {
        if(isFull())
            return false;

        items[++rear] = data;
        return true;
    }

    bool dequeue(int &data) {
        if(isEmpty())
            return false;
        data = items[front++];
        return true;
    }
    
    int lives()
    {
    	return live;
	}
	
	int randomNumber()
	{
		n = rand() % 70 + 20;
		
		return n;
	}
};

int main()
{
	Queue que;
	int guess, number, live;
	live = que.lives();
	number = que.randomNumber();
	cout << number << endl;
	cout << "I have randomly picked a number between 20 and 70." << endl;
	
	do	
	{
		cout << "Enter your guess: ";
		cin >> guess;
		que.enqueue(guess);
		
		if(guess > number)
		{
			cout << "You guessed higher!  Lives left: " << live << endl;
		}
		
		else if(guess < number)
		{
			cout << "You guessed lower!  Lives left: " << live << endl;
		}
		if(live == 0)
		{
			cout << "You have no lives remaining! Game over! The number was " << number << "." << endl;
			break;
		}
		live--;
	}while(guess != number);
	
	int first;
	int best;
	int min = 1;
	
	cout << "Your guesses were: ";
	for (int i = 0; i < 5; i++)
	{
		que.dequeue(first);
		cout << first << " ";
		
		if(number - first < min)
		{
			min = first;
		}
	}
	
	cout << endl << "Your best guess was " << min << "." << endl;
	
	return 0;
}
