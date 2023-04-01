#include <iostream>
#include <cmath>
using namespace std;
class PlayWithNum
{
    public:
        int rev;
        int takeinp()
        {
            int temp;
            cout << "Enter Value" << endl;
            cin >> temp;
            return temp;
        }
        void disp(int m)
        {
            cout << "Value : " << m <<  endl;
        }
        int calculate(char p, int m)
        {
            int actualInt = m;
            rev = 0;
            while(actualInt >= 10)
            {
                rev = (rev + actualInt%10)*10;
                actualInt = actualInt/10;
            }
            rev = (rev + actualInt%10);
            return rev;
        }
        void calculate(int m, char r)
        {
            bool flag = false;
            for(int i=2; i<sqrt(m); i++)
            {
                if(m%i == 0)
                {
                    flag = true;
                }
            }
            if(flag)
            {
                cout << "Not Prime." << endl;
            }
            else
            {
                cout << "Prime" << endl;
            }
        };
};
int main()
{
    int f;
    PlayWithNum hi;
    f = hi.takeinp();
    hi.disp(f);
    f = hi.calculate('r', f);
    hi.disp(f);
    hi.calculate(f, 'p');
    return 0;
}