#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;
PII p[1010];

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    //while(cin >> n, n)
    {
        int idx = 0;
        memset(p, 0, sizeof p);
        set<LL> s, l, r; 
        
        for(int i = 0; i < n; i ++ )
        {
            LL x;   cin >> x;
            s.insert(x);
        }
        if(s.size() == 1)   cout << 1 << "/" << 1 << endl;
        else
        {
            int last = -1;
            for(auto &x : s)
            {
                if(last == -1) last = x;
                else
                {
                    LL d = gcd(last, x);
                    p[idx ++ ] = {last / d, x / d};
                    last = x;
                }
            }
        }
        // cout << "case" << endl;
        // for(int i = 0; i < idx; i ++ )
        //     cout << p[i].x << " " << p[i].y << endl;
        
        for(int i = 0; i < idx; i ++ )
        {
            l.insert(p[i].x);
            r.insert(p[i].y);
        }
        
        if(l.size() == 1 && r.size() == 1)   cout << *r.begin() << "/" << *l.begin() << endl;    
        else
        {
            LL ll = -1, rr = -1;
            for(int i = 0; i < idx; i ++ )
            {
                if(ll == -1)    ll = p[i].x;
                else    ll = min(ll, (LL)p[i].x / ll);
                
                if(rr == -1)    rr = p[i].y;
                else    rr = min(rr, (LL)p[i].y / rr);
            }
            cout << rr << "/" << ll << endl;
        }
    }
    return 0;
}