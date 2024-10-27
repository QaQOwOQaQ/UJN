#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100010;

int n, q, pre[N], p[N], k;
bool st[N];

int find(int x)
{
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

int main()
{
    for(int i = 0; i < N; i ++ )    pre[i] = i;

    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> k;
        for(int i = 0; i < k; i ++ )    
        {
            cin >> p[i];
            if(i)   pre[find(p[i])] = find(p[0]);
            st[p[i]] = true;
        }
    }
    
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i < N; i ++ )
    {
        if(st[i])   cnt1 ++ ;
        if(st[i] && find(i) == i)  cnt2 ++ ;
    }
    cout << cnt1 << " " << cnt2 << endl;
    
    cin >> q;
    while(q -- )
    {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b))  puts("Y");
        else    puts("N");
    }
    return 0;
}