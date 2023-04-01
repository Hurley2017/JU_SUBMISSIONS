#include <iostream>
#include <cmath>
using namespace std;
class MyString
{
    private:
        char *core;
    public:
        MyString()
        {

        }
        MyString(const char *f)
        {
            core = (char *)malloc(len(f)*sizeof(char));
            store(core, f);
        }
        MyString operator+(MyString addent)
        {
            int cursor = 0;
            MyString result;
            result.core = (char *)malloc((len(this->core)+len(addent.core))*sizeof(char));
            store((result.core+cursor), this->core);
            cursor = len(this->core);
            store((result.core + cursor), addent.core);
            rev(result.core);
            return result.core;
        }
        void disp()
        {
            cout << core << endl;
        }
        void store(char *subject, const char *object)
        {
            int cursor = 0;
            while(*(object + cursor) != '\0')
            {
                *(subject + cursor) = *(object + cursor);
                cursor++;
            }
            *(subject+cursor) = '\0';
        }
        int len(const char *subject)
        {
            int count = 0;
            while(*(subject + count) != '\0')
            {
                count++;
            }
            return count;
        }
        void rev(char *subject)
        {
            char *temp;
            int cursorleft = 0, cursorright = len(subject);
            int whilec = cursorright;
            temp = (char *)malloc(cursorright*sizeof(char));
            while(cursorleft < whilec)
            {
                *(temp + cursorleft) = *(subject + cursorright-1);
                cursorleft++;
                cursorright--;
            }
            *(temp + cursorleft) = '\0';
            store(subject, temp);
        }
};
int main()
{
    MyString s1("I "), s2("cannot code.");
    s1.disp();
    s2.disp();
    MyString s3 = s1 + s2;
    s3.disp();
    return 0;
}