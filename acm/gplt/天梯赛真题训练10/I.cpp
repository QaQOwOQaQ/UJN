#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

typedef pair<int, int> PII;

int l, r, cnt, idx;
bool st[101000];
PII res[101000];

bool check(int x)
{
    int y = x;
    bool flag = true;
    for(int i = 2; i <= x / i; i ++ )
        if(x % i == 0) 
        {
            flag = false;
            break;
        }
    
    unordered_set<int> s;
    
    while(x != 1)
    {
        int sum = 0;
        while(x)
        {
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        if(s.count(sum))    return false;
        x = sum;
        s.insert(x);
    }
    
    for(auto &x : s)    st[x] = true;
    int p = s.size();
    if(flag)    p <<= 1;
    res[idx ++ ] = {y, p};
    
    return true;
}

int main()
{
    cin >> l >> r;
    for(int i = l; i <= r; i ++ )
    {
        if(check(i))    cnt ++ ;
    }
    if(!cnt)    puts("SAD");
    for(int i = 0; i < idx; i ++ )
    {
        if(!st[res[i].first])
            cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
