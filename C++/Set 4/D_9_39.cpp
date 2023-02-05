#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;
inline double square(double a)
{
    return pow(a, 2);
}
int main()
{
    double n; 
    cout << "Enter Data : ";
    cin >> n;
    cout << "Answer is " << square(n) << endl;
    return 0;
}