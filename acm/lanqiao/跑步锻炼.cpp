//跑步锻炼
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int y1 = 2000, y2 = 2020;
    int m1 = 1, m2 = 10;
    int d1 = 1, d2 = 1;
    int w = 6;  //week
    
    int res = 0;    
    while(1)
    {
        if(y1 == y2 && m1== m2 && d1 == 2)   break;
        if(w == 1 || d1 == 1)   res += 2;
        else    res += 1;
        
        d1 ++ ;
        w ++ ;
        if(w == 8)  w = 1;
        
        if(m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12) //31
        {
            if(d1 == 32)
            {
                d1 = 1;
                m1 ++ ;
            }
        }
        else if(m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
        {
            {
                if(d1 == 31)
                {
                    d1 = 1;
                    m1 ++ ;
                }
            }
        }
        else    //m1 == 2
        {
            if(y1 % 400 == 0 || (y1 % 4 == 0 && y1 % 100 != 0)) //29
            {
                if(d1 == 30)
                {
                    d1 = 1;
                    m1 ++ ;
                }
            }
            else    //28
            {
                if(d1 == 29)
                {
                    d1 = 1;
                    m1 ++ ;
                }
            }
        }
        if(m1 == 13)
        {
            y1 ++ ;
            m1 = 1;
        }
    }
    
    cout << "res: " << res << endl;
    
    return 0;
}