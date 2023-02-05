#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;
class Number_List
{
    private:
        int i, j, limit, sizearr, *arr;
    public:
        Number_List(int n)
        {
            limit = n;
        }
        void createArr()
        {
            cout << "Calling Create function." << endl;
            cout << "Enter size of the array : ";
            cin >> sizearr;
            arr = (int *)malloc(sizearr*sizeof(int));
            for(i = 0; i<sizearr; i++)
            {
                *(arr+i) = rand()%limit;
            }
            cout << "Successfully created the array." << endl;
        }
        void displayArr()
        {
            cout << "Calling display function : " << endl;
            for(i = 0; i<sizearr; i++)
            {
                cout << *(arr + i) << "\t";
            }
            cout << endl;
        }
        void sortArr()
        {
            cout << "Calling sort function :" << endl;
            for(i = 0; i<sizearr-1; i++)
            {
                for(j = i; j<sizearr; j++)
                {
                    if(*(arr+i) > *(arr + j))
                    {
                        int temp = *(arr + i);
                        *(arr + i) = *(arr + j);
                        *(arr + j) = temp;
                    }
                }
            }
            cout << "Sorted successfully." << endl;
        }
        void voidMin()
        {
            cout << "Calling Min function :" << endl;
            int min = INT_MAX;
            for(i = 0; i<sizearr; i++)
            {
                if(min > *(arr + i))
                {
                    min = *(arr + i);
                }
            }
            cout << "Minimum element of the array is " << min << endl;
        }
        void voidMax()
        {
            cout << "Calling Max function :" << endl;
            int max = INT_MIN;
            for(i = 0; i<sizearr; i++)
            {
                if(max < *(arr + i))
                {
                    max = *(arr + i);
                }
            }
            cout << "Maximum element of the array is " << max << endl;
        }
};
int main()
{
    int sw;
    srand(time(0));
    Number_List n(1000);
    n.createArr();
    n.displayArr();
    n.sortArr();
    n.displayArr();
    n.voidMin();
    n.voidMax();
    return 0;   
}