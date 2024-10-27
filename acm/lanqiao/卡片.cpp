#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10];

bool check()
{
    for(int i = 0; i <= 9; i ++ )
        if(a[i] < 0)
            return false;
    return true;
}

int main()
{
    for(int i = 0; i <= 9; i ++ )   a[i] = 2021;
    
    for(int i = 1; ; i ++ )
    {
        int x = i;
        while(x)
        {
            a[x % 10] -- ;
            x /= 10;
        }
        if(!check())  
        {
            cout << i - 1 << endl;
            break;
        }
    }
    
    return 0;
}