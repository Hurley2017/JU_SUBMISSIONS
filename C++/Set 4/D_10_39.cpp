#include <iostream>
#include <cmath>
#define pI 3.141
using namespace std;
class Shapes
{
    public:
        Shapes()
        {
            
        }
        double calVal(double length)
        {
            // CUBE
            return pow(length, 3);
        };
        double calVal(double height, double width, double length)
        {
            // CUBOID
            return height*width*length;
        };
        double calVal(double radius, double height)
        {
            // CYLINDER
            return height*pI*pow(radius, 2);
        };
        double calVal(double radius, bool load)
        {
            // Sphere
            return (4/3)*pI*pow(radius, 2);
        }
        double calVal(double height, double radius, bool load)
        {
            // CONE
            return (pI/3)*height*pow(radius, 2);
        }
};
int main()
{
    Shapes s;
    int sw;
    bool f;
    double height, radius, length, width, restart;
    restart:
    cout << "Choose from the following : \n1) Cube\n2) Cuboid\n3) Cylinder\n4) Sphere\n5) Cone\n6) Exit\nEnter choice : ";
    cin >> sw;
    switch(sw)
    {
        case 1:
            cout << "For Cube" << endl;
            cout << "Enter length : ";
            cin >> length;
            cout << "Answer is " << s.calVal(length) << endl;
            goto restart;
        case 2:
            cout << "For Cuboid" << endl;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter length : ";
            cin >> length;
            cout << "Enter width : ";
            cin >> width;
            cout << "Answer is " << s.calVal(height, width, length) << endl;
            goto restart;
        case 3:
            cout << "For Cylinder" << endl;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter radius : ";
            cin >> radius;
            cout << "Answer is " << s.calVal(radius, height) << endl;
            goto restart;
        case 4:
            cout << "For Sphere" << endl;
            cout << "Enter radius : ";
            cin >> radius;
            cout << "Answer is " << s.calVal(radius, f) << endl;
            goto restart;
        case 5:
            cout << "For Cone" << endl;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter radius : ";
            cin >> radius;
            cout << "Answer is " << s.calVal(height, radius, f) << endl;
            goto restart;
        case 6:
            break;
        default:
            cout << "Bad choice." << endl;
            goto restart;
    }
    return 0;
}