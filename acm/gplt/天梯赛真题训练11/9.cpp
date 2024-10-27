#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m, k;
int a[N];
bool st[N];

bool check()
{
    //降序个数不能>m（不要求连续！）
    int dc = -1, now = -1;
    for(int i = 1; i <= n; i ++ )
    {
        if(dc == -1)        now = a[i], dc = 1;
        else if(a[i] < now) dc ++ , now = a[i];
        else    dc = 1, now = a[i];
        if(dc > m)  return false;
    }
    if(dc > m)  return false;
    
    // cout << "长度合法" << endl;
    
    //一个大数后面的所有小数必须是降序的
    for(int i = 1; i <= n; i ++ )
    {
        int last = -1;
        for(int j = i + 1; j <= n; j ++ )
        {
            if(a[j] < a[i])
            {
                if(last == -1)  last = a[j];
                else if(a[j] < last) last = a[j];
                else    return false;
            }
        }
    }
    
    //多次出栈??
    memset(st, false, sizeof st);
    for(int i = 1; i <= n; i ++ ) st[a[i]] = true;
    for(int i = 1; i <= n; i ++ )   
        if(!st[i])
            return false;
    
    return true;
}

int main()
{
    cin >> m >> n >> k;
    
    while(k -- )
    {
        for(int i = 1; i <= n; i ++ )   cin >> a[i];
        if(check())  puts("YES");
        else    puts("NO");
    }
    
    return 0;
}