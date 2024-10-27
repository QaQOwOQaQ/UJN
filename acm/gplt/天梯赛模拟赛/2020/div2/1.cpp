// 栈
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n, m, q;
int a[N];

// check1: 1~N 入栈，出栈序列中，所有比k小的数都是递减的
bool check_valid()
{
    for(int i = 1; i <= n; i ++ )
    {
        int minx = a[i];
        for(int j = i + 1; j <= n; j ++ )
        {
            if(a[j] > a[i]) continue;
            if(a[j] < minx) minx = a[j];
            else    return false;
        }
    }
    return true;
}

// check2: 任意时刻栈中的元素是否小于 m
bool check_column()
{
    for(int i = 1; i <= n; i ++ )
    {
        int j = i + 1;
        while(j <= n && a[j] < a[i])  j ++ ;
        if(j - i > m)   return false;
        i = j - 1;
    }
    return true;
}

int main()
{
    cin >> m >> n >> q;
    while(q -- )
    {
        bool flag = true;
        for(int i = 1; i <= n; i ++ )   cin >> a[i];
        
        if(!check_valid() || !check_column())   puts("NO");
        else    puts("YES");
    }
    return 0;
}