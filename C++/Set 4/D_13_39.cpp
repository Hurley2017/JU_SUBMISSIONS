#include <iostream>
#include <cmath>
using namespace std;
class EyeOfAgamotto
{
    private:
        int hour, minute, second;
    public:
        EyeOfAgamotto()
        {
            hour = minute = second = 0;
        }
        EyeOfAgamotto operator==(EyeOfAgamotto object)
        {
            bool ret = (this->hour == object.hour || this->minute == object.minute || this->second == object.second);
            if(ret)
            {
                cout << "Equal" << endl;
            }
            else
            {
                cout << "Not Equal" << endl;
            }
        }
        EyeOfAgamotto operator+(EyeOfAgamotto object)
        {
            EyeOfAgamotto result;
            result.second = this->second + object.second;
            if(result.second >= 60)
            {
                result.minute = this->minute + object.minute + 1;
                result.second = result.second - 60;
            }
            else
            {
                result.minute = this->minute + object.minute;
            }
            if(result.minute >= 60)
            {
                result.hour = this->hour + object.hour;
                result.minute = result.minute - 60;
            }
            else
            {
                result.hour = this->hour + object.hour;
            }
            return result;
        }
        EyeOfAgamotto operator>> (const char *time)
        {
            int cursor = 0, intwhile = 0;
            hour = minute = second = 0;
            while(*(time + cursor) != '\0')
            {
                if(*(time + cursor) == ':')
                {
                    intwhile++;
                }
                else
                {
                    switch(intwhile)
                    {
                        case 0:
                            hour = hour*10 + (*(time + cursor)-48);
                            break;
                        case 1:
                            minute = minute*10 + (*(time + cursor)-48);
                            break;
                        case 2:
                            second = second*10 + (*(time + cursor)-48);
                            break;
                        default:
                            break;
                    }
                }
                cursor++;
            }
        }
        EyeOfAgamotto operator<< (int h)
        {
            cout << hour << ":" << minute << ":" << second << endl;
        }
};
int main()
{
    EyeOfAgamotto f1, f2, f3;
    f1 << 2;
    f1 >> "12:20:30";
    f1 << 2;
    f2 >> "12:20:30";
    f2 << 2;
    f3 = f1 + f2;
    f3 << 2;
    f1 == f2;
    return 0;
}
