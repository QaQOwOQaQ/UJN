#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

vector<int> g[N];
int n;
PII w[N];

void dfs(int u)
{
    queue<int> q;
    q.push(u);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(auto &x : g[t])
        {
            w[x].x = w[t].x + 1;
            q.push(x);
        }
        
    }
}

bool cmp(PII a, PII b)
{
    if(a.x == b.x)  return a.y < b.y;
    return a.x > b.x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;  cin >> x;
        if(x == -1)  x = 0;
        g[x].push_back(i);
        w[i].y = i;
    }
    
    dfs(0);
    
    sort(w + 1, w + n + 1, cmp);
    
    vector<int> res;
    for(int i = 1; i <= n; i ++ )
    {
        if(w[i].x == w[1].x)    res.push_back(w[i].y);
        else    break;
    }
    
    cout << w[1].x << endl;
    for(int i = 0; i < res.size(); i ++ )
    {
        cout << res[i];
        if(i != res.size() - 1) cout << " ";
    }
    
    return 0;
}