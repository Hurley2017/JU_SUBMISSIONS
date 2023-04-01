#include <iostream>
#include <cmath>
using namespace std;
class Triangle
{
    private:
        double A, B, C, S; 
    public:
        long double Area, Perimeter;
        void setVal(double A, double B, double C)
        {
            this->A = A;
            this->B = B;
            this->C = C;
            S = (A + B + C)/2;
        }
        void calculateArea()
        {
            Area = sqrt(S*(S-A)*(S-B)*(S-C));            
        }
        void calculatePerimeter()
        {
            Perimeter = S*2;
        }
};
void takeinp(Triangle *T)
{
    double A, B, C;
    cout << "Enter AB : ";
    cin >> A;
    cout << "Enter BC : ";
    cin >> B;
    cout << "Enter CA : ";
    cin >> C;
    T->setVal(A, B, C);
}
void displayinp(Triangle T)
{
    cout << "Area of the triangle is " << T.Area << endl;
    cout << "Perimeter of the triangle is " << T.Perimeter << endl;
}
int main()
{
    Triangle T;
    takeinp(&T);
    T.calculatePerimeter();
    T.calculateArea();
    displayinp(T);
    return 0;
}