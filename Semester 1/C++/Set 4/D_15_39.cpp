#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;
class Complex
{
    private:
        int real;
        int imaginerycross;
    public:
        Complex()
        {
            real = 0;
            imaginerycross = 0;
        }
        Complex(int a)
        {
            real = a;
            imaginerycross = 0;
        }
        Complex(int a, int b)
        {
            real = a;
            imaginerycross = b;
        }
        void show()
        {
            cout << real << "+" << imaginerycross << "i" << endl;
        }
        friend void sum(Complex, Complex, Complex*);         
};
void sum(Complex a, Complex b, Complex *c)
{
    c->real = a.real + b.real;
    c->imaginerycross = a.imaginerycross + b.imaginerycross;
}
int main()
{
    
    Complex A(5,6), B(6), C;
    A.show();
    B.show();
    C.show();
    sum(A, B, &C);
    C.show();
    return 0;
}