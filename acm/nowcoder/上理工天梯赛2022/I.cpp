#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2000010;

int n, a[N], cnt[N];
int tr[M][20], idx;

void Insert(int x)
{
    string str = to_string(x);
    while(str.size() < 6)   str = "0" + str;
    int p = 0;
    for(int i = 0; str[i]; i ++ )
    {
        int u = str[i] - '0';
        if(!tr[p][u])   tr[p][u] = ++ idx;
        p = tr[p][u];
        cnt[p] ++ ;//??
    }
}

int query(int x)
{
    string str = to_string(x);
    while(str.size() < 6)   str = "0" + str;
    int p = 0, ans = 0;
    for(int i = 0; str[i]; i ++ )
    {
        int u = 9 - (str[i] - '0');
        while(1)
        {
            if(cnt[tr[p][u]])
            {
                p = tr[p][u];
                ans = ans * 10 + (u + str[i] - '0') % 10;
                break;
            }
            u -- ;
            if(u < 0)   u = 9;
        }
    }
    return ans;
}

void erase(int x)
{
    string str = to_string(x);
    while(str.size() < 6)   str = '0' + str;
    int p = 0;
    for(int i = 0; str[i]; i ++ )
    {
        int u = str[i] - '0';
        p = tr[p][u];
        cnt[p] -- ;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> a[i];
        Insert(a[i]);
    }
    
    for(int i = 0; i < n; i ++ )
    {
        erase(a[i]);
        int res = query(a[i]);
        cout << res << " ";
        Insert(a[i]);
    }
    cout << endl;
    
    
    return 0;
}