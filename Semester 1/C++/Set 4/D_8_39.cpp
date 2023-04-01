#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;
class Data
{
    private:
        int number;
    public:
        Data()
        {
            cout << "Data is here." <<endl;
        }
        Data(Data &subject)
        {
            this->number = subject.number;
        }
        Data(int n)
        {
            number = n;
        }
        virtual ~Data()
        {
            cout << "Destructor Called." << endl;
        }
        int getNum()
        {
            return number;
        }       
};
class Dummy : public Data
{

    public:
        int f = 10;
        Dummy()
        {
            cout << "Dummy is here!" <<endl;
        }
        ~Dummy()
        {
            cout << "Dummy dies." <<endl;
        }
};
int main()
{
    Data ob1(5), ob2(ob1);
    cout << ob1.getNum() << endl;
    cout << ob2.getNum() << endl;
    Data *d = new Dummy();
    delete d;
    return 0; 
}