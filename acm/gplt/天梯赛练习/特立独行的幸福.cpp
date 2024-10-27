#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int l, r, idx;
PII w[N];
set<int> pre;

bool is_prime(int x)
{
    if(x < 2)   return false;
    for(int i = 2; i <= x / i; i ++ )
        if(x % i == 0)  return false;
    return true;
}

inline int sqr(int x)
{
    return x * x;
}

int get(int x)
{
    int res = 0;
    while(x)
    {
        res += sqr(x % 10);
        x /= 10;
    }
    return res;
}

int check(int x)
{
    int u = x;
    set<int> s;
    while(x != 1)
    {
        int t = get(x);
        if(s.count(t))  return 0;
        s.insert(t);
        x = t;
    }
    s.insert(1);
    for(auto &x : s)    pre.insert(x);
    if(is_prime(u))  return s.size() * 2;
    return s.size();
}

int main()
{
    cin >> l >> r;
    for(int i = l; i <= r; i ++ )
        if(check(i))
            w[idx ++ ] = {i, check(i)};
            
        
    
    if(!idx)    puts("SAD");
    else
    {
        for(int i = 0; i < idx; i ++ )
            if(!pre.count(w[i].first))
                cout << w[i].first << " " << w[i].second << endl;
    }
    
    return 0;
}