#include <iostream>
#include <string>

using namespace std;

class Calculator
{
    private:
        int length;
        float *numbers;
    public:
        Calculator()
        {
            length = 0;
            //No args constructor called
        }

        Calculator(int a)
        {
            numbers = new float(a);         //dynamic
            length = a;                     //Stores the size of array
            //Overload Constructor called
        }

        void get_numbers()
        {
            //Getting the numbers
            for (int i = 0; i <length; i++)
            {
                cin >> numbers[i];
            }
        }

        ~Calculator()
        {
            delete[] numbers; //Destructor
        }

        Calculator operator + (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = numbers[i] + x.numbers[i];
            }

            return storage;
        }

        Calculator operator - (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = numbers[i] - x.numbers[i];
            }

            return storage;
        }

        Calculator operator * (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = numbers[i] * x.numbers[i];
            }

            return storage;
        }

        Calculator operator / (const Calculator &x)
        {
            Calculator storage (x.length);

            for (int i = 0; i < x.length; i++)
            {
                storage.numbers[i] = numbers[i] / x.numbers[i];
            }

            return storage;
        }

        friend ostream& operator << (ostream &os ,const Calculator &x)
        {
            for (int i = 0; i <x.length; i++)
            {
                os << x.numbers[i] << " ";
            }
            return os;
        }
};

int main()
{
    int len1, len2;
    string choose;

    cout << "Length of the first number set: ";
    cin >> len1;

    Calculator a (len1);

    a.get_numbers();

    cout << "First set entered: ";

    cout << a << endl;

    cout <<"Length of the second number set: ";
    cin >> len2;

    Calculator b (len2);

    b.get_numbers();

    cout << "Second set entered: ";

    cout << b << endl;

    do {
        cin >> choose;

        if(choose == "+")
        {
            cout << a + b;
        }

        else if(choose == "-")
        {
            cout << a - b;
        }

        else if (choose == "*")
        {
            cout << a * b;
        }

        else if (choose == "/")
        {
            cout << a / b;
        }

        else if (cout == "exit")
        {
            break;
        }

        else
        {
            cout << "Please make sure you entered right operator." << endl;
        }

    }while(choose != "exit");
    return 0;

}

