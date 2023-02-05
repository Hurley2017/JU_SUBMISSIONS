#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;
class String
{
    private:
        int i, size;
        char *in;
    public:
        String()
        {
            i = 0;
        }
        String(const char in[])
        {
            i = 0;
            size = strlen(in);
            this->in = (char *)malloc(size*sizeof(char));
            while(i<size)
            {
                *(this->in + i) = *(in + i);
                i++;
            }
        }
        void dispStr()
        {
            fputs(this->in, stdout);
        }
        void join(String a)
        {
            i = 0;
            this->in = (char*)realloc(this->in, (a.size+size)*sizeof(char));
            while(i < a.size)
            {
                *(this->in + i + size) = *(a.in + i);
                i++;
            }
        }    
};
int main()
{
    String one("Hello "), two("World.");
    one.dispStr();
    cout << endl;
    two.dispStr();
    cout << endl;
    one.join(two);
    one.dispStr();
    cout << endl;
    return 0;
} 