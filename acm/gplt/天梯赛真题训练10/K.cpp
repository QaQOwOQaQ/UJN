#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, pre[N], dist[N];
vector<int> g[N];
bool st[N];

void dijkstra(int root)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, root});
    dist[root] = 0;
    
    while(q.size())
    {
        auto t = q.top();
        q.pop();
        int distance = t.first, ver = t.second;
        if(st[ver]) continue;
        st[ver] = true;
        int len = g[ver].size();
        for(int i = 0; i < len; i ++ )
        {
            int j = g[ver][i];
            if(dist[j] > distance + 1)
            {
                dist[j] = distance + 1;
                q.push({dist[j], j});
            }
        }
    }
    
}

int main()
{
    memset(pre, -1, sizeof pre);
    cin >> n;
    for(int i = 1; i <= n; i ++ )   
    {
        int k;  cin >> k;
        while(k -- )
        {
            int x;  cin >> x;
            g[i].push_back(x);
            pre[x] = i;
        }
    }
    
    int root;
    for(int i = 1; i <= n; i ++ )
        if(pre[i] == -1)    
        {
            root = i;
            break;
        }
    
    // cout << "root: " << root << endl;
    dijkstra(root);
    
    int maxn = -1, id = -1;
    for(int i = 1; i <= n; i ++ )
        if(dist[i] > maxn)  maxn = dist[i], id = i;
    
    cout << id << endl;
    return 0;
}