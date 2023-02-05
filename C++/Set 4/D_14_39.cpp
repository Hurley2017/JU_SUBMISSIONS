#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;
class A
{
    private:
        int a, b;
    public:
        A(int a, int b)
        {
            this->a = a;
            this->b = b;
        }
        void displayMem()
        {
            cout << "a is " << a << endl;
            cout << "b is " << b << endl;
        }
        friend void swapi(A);
};
void swapi(A f)
{
    f.a = f.a + f.b;
    f.b = f.a - f.b;
    f.a = f.a - f.b;
    f.displayMem();
}
int main()
{
    int a, b;
    cout << "Enter first variable : ";
    cin >> a;
    cout << "Enter Second variable : ";
    cin >> b;
    A f(a, b);
    f.displayMem();
    swapi(f);
    return 0;
}