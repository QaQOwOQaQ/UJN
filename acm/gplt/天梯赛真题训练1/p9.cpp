#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int n, m, k;
set<int> s[55];
    
double work(int a, int b)
{
    set<int> S;
    // for(auto &x : s[a]) S.insert(x);
    // for(auto &x : s[b]) S.insert(x);
    
    int equal = 0, all = 0;
    for(auto &x : s[a])
        if(s[b].count(x))    equal ++ ;
    all = s[a].size() + s[b].size() - equal;
    return (double)equal / all * 100;
}

int main()
{

    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> m;
        for(int j = 0; j < m; j ++ )
        {
            int x;
            cin >> x;
            s[i].insert(x);
        }
    }
    cin >> k;
    while(k -- )
    {
        int a, b;
        cin >> a >> b;
        double res = work(-- a, -- b);
        printf("%.2f%\n", res);
    }
    
    return 0;
}