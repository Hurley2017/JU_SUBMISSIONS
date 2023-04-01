#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;
class Year
{
    private:
        int y;
        bool isLeapYear;
    public:
        Year(int n)
        {
            y = n;
            isLeapYear = false;
        }
        ~Year()
        {
            cout << "Destructor is called." << endl;
        }
        bool check()
        {
            if(y%4 == 0 && y%100 != 0)
            {
                isLeapYear = true;        
            }
            else if(y%4 == 0 && y%100 == 0)
            {
                if(y%400 == 0)
                {
                    isLeapYear = true;
                }
                else
                {
                    isLeapYear = false;
                }
            }
            else
            {
                isLeapYear = false;
            }
            return isLeapYear;
        }    
};
int main()
{
    Year inp(2000);
    if(inp.check())
    {
        cout << "It is Leap Year." << endl;
    }
    else
    {
        cout << "It is not Leap Year." << endl;
    }
    return 0;
}