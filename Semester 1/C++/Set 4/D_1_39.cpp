#include <iostream>
#include <cmath>
#define pI 3.1415
using namespace std;
class Circle
{
    private:
        double radianPri, areaPri;
    protected:
        double radianPro, areaPro;
    public:
        void setVal()
        {
            cout << "Enter Private Radian Value : ";
            cin >> radianPri;
            cout << "Enter Protected Radian Value : ";
            cin >> radianPro;
        }
        void calcAreaPri()
        {
            areaPri = pI*radianPri*radianPri;
        }
        void calcAreaPro()
        {
            areaPri = pI*radianPro*radianPro;
        }
        void disp()
        {
            cout << "Private : " << radianPri << endl;
            cout << "Protected : " << radianPro << endl;
        }
};
class DerivedCircle : protected Circle
{
    public:
        void PrintProtected()
        {
            cout << "Protected : " << areaPro << endl;
        }
};
int main()
{
    Circle c1;
    c1.setVal();
    c1.calcAreaPri();
    c1.calcAreaPro();
    c1.disp();
    DerivedCircle c2;
    c2.PrintProtected();
    return 0;
}