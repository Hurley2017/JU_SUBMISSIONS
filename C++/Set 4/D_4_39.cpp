#include <iostream>
#include <cmath>
using namespace std;
class Pattern
{
    private:
        int ls, fs;
    public:
        Pattern()
        {
            cout << "Enter starting pattern number : " << endl;
            cin >> fs;
            ls = 0;
        }
        void runPattern()
        {
            while(fs >= 1)
            {
                printPattern(ls, fs);
                cout << endl;
                ls++;
                fs = fs - 2;
            }
        }
        void printPattern(int ls, int fs)
        {
            int l = 0, f = 0, e = 0;
            //Leading space:
            for(l = 0; l < ls; l++)
            {
                cout << " "; 
            }
            //Filling star:
            for(f = 0; f < fs; f++)
            {
                cout << "*";
            }
        }

};
int main()
{
    Pattern p;
    p.runPattern();
    return 0;
}