#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int get(int i)
{
    int cnt = 0;
    while(i)
    {
       int t = i % 10;
       if(t == 2)   cnt ++ ;
       i /= 10;
    }
    
    return cnt;
}

int main()
{
    int res = 0;
    for(int i = 1; i <= 2020; i ++ )    res += get(i);
    
    cout << res << endl;
    
    return 0;
}