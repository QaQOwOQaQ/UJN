#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{/*
    for(int t = 0; t < 10; t ++ )
    {
        for(int i = 1; i <= 32; i ++ )
        {
            int x;  cin >> x;
            x = (x + 128) % 128;
            for(int j = 7; j >= 0; j -- )
            {
                if(x >> j & 1)  cout << "*";
                else    cout << " ";
            }
            if(i % 2 == 0)  cout << endl;
        }   
    }
    */
    //cout << "九的九次方等于多少" << endl;
    long long res = 1;
    for(int i = 1; i <= 9; i ++ )    res *= 9;
    cout << res << endl;
    return 0;
}