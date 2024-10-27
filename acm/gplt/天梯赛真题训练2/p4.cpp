#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, k, m, a[N];
bool st[N], num[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> k;
        int x;
        if(k == 1)  cin >> x;
        else
        {
            for(int i = 0; i < k; i ++ )
            {
                cin >> x;
                st[x] = true;
            }
        }
    }
    
    cin >> m;
    int cnt = 0;
    bool has_res = false;
    for(int i = 0; i < m; i ++ )
    {
        int x;
        cin >> x;
        if(!st[x] && !num[x])   
        {
            a[cnt ++ ] = x;
            num[x] = true;
            has_res = true;
        }
    }
    if(!has_res)    cout << "No one is handsome";
    else
    {
        for(int i = 0; i < cnt; i ++ ) 
        {
            printf("%05d", a[i]);
            if(i != cnt - 1)    cout << " ";
        }
    }
    return 0;
}