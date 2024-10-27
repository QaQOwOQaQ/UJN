/*
    socre:17
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2100;

int n, m, a, b;
double w[N][N];

/*
    不会在同一张照片里出现多次
    负号表示女性
    男:0 ~ 999
    女:-999 ~ -1
    -> 1001 - 1999
*/

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        vector<int> g;
        int k; cin >> k;
        for(int i = 0; i < k; i ++ )
        {
            int x;  cin >> x;
            if(x < 0)   x += 2000;
            g.push_back(x);
        }
        for(int i = 0; i < k; i ++ )
            for(int j = 0; j < k; j ++ )
                if(i != j)
                    w[g[i]][g[j]] += 1.0 / k;
    }
    
    // cout << "test: " << w[1997][0] << endl;
    
    cin >> a >> b;
    
    double maxa = -1, maxb = -1;
    vector<int> g1, g2;
    bool f1 = false, f2 = false;
    
    //A
    if(a < 0)   a += 2000;
    for(int i = 0; i <= 2010; i ++ )
    {
        if(a >= 1000 && i >= 1000)   continue;
        if(a < 1000 && i < 1000)   continue;
        maxa = max(maxa, w[a][i]);
    }
    for(int i = 1; i <= 2010; i ++ )
        if(w[a][i] == maxa) 
        {
            if(a >= 1000 && i >= 1000)   continue;
            if(a < 1000 && i < 1000)   continue;
            g1.push_back(i);
            if(i == b)  f1 = true;
        }
        
        
    //B
    if(b < 0)   b += 2000;
    for(int i = 1; i <= 2010; i ++ )
    {
        if(b >= 1000 && i >= 1000)   continue;
        if(b < 1000 && i < 1000)   continue;
        maxb = max(maxb, w[b][i]);
    }
    for(int i = 0; i <= 2010; i ++ )
        if(w[b][i] == maxb) 
        {
            if(b >= 1000 && i >= 1000)   continue;
            if(b < 1000 && i < 1000)   continue;
            g2.push_back(i);
            if(i == a)  f2 = true;
        }
    
    // cout << "max: " << maxa << ' ' << maxb << endl;
    
    
    if(f1 && f2)
    {
        // cout << "圆满" << endl;
        if(a > 1000)    a -= 2000;
        if(b > 1000)    b -= 2000;
        cout << a << ' ' << b << endl;
    }
    
    else
    {
        if(a > 1000)    a -= 2000;
        if(b > 1000)    b -= 2000;
        if(a < 0)   sort(g1.begin(), g1.end(), greater<int>());
        else    sort(g1.begin(), g1.end());
        
        if(b < 0)   sort(g2.begin(), g2.end(), greater<int>());
        else    sort(g2.begin(), g2.end());
        for(auto &x : g1)   
        {
            if(x > 1000)    x -= 2000;
            cout << a << ' ' << x << endl;
        }
        for(auto &x : g2)  
        {
            if(x > 1000)    x -= 2000;
            cout << b << ' ' << x << endl;
        }
    }
    
    
    return 0;
}