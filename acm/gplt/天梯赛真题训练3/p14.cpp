#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> PII;

const int N = 300, M = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m, hh, tt, id;
int h[N], e[M], ne[M], w[M], idx;
int enemy[N], kill[N], city[N], path[N];
int dist[N], pre[N];
bool st[N];
map<int, string> its;   //输出的时候将编号转换为字符串
map<string ,int> sti;   //输入的时候将字符串转换为编号

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void djikstra(int u)
{
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    
    priority_queue<PII, vector<PII>, greater<PII> > q;
    dist[u] = 0; 
    city[u] = 1; kill[u] = enemy[u]; path[u] = 1; 
    
    q.push({dist[u], u});
    while(q.size())
    {
        auto t = q.top();   q.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                pre[j] = ver;
                q.push({dist[j], j});
                
                city[j] = city[ver] + 1;
                kill[j] = kill[ver] + enemy[j];
                path[j] = path[ver];
            }
            else if(dist[j] == distance + w[i])
            {
                path[j] += path[ver];
                if(city[j] < city[ver] + 1)
                {
                    pre[j] = ver;
                    
                    city[j] = city[ver] + 1;
                    kill[j] = kill[ver] + enemy[j];
                }
                else if(city[j] == city[ver] + 1)
                {
                    if(kill[j] < kill[ver] + enemy[j])
                    {
                        pre[j] = ver;
                        kill[j] = kill[ver] + enemy[j];
                    }
                }
            }
        }
    }
    
}

void out(int u)
{
    if(pre[u] == -1)
    {
        cout << its[u];
        return ;
    }
    out(pre[u]);
    cout << "->" << its[u];
}

int main()
{
    string s, ss;
    int v;
    
    memset(pre, -1, sizeof pre);
    memset(h, -1, sizeof h);
    
    cin >> n >> m >> s >> ss;
    
    sti[s] = id;   its[id] = s; hh = id ++ ;
    sti[ss] = id;  its[id] = ss; tt = id ++ ;
    for(int i = 0; i < n - 1; i ++ )
    {
        cin >> s >> v;
        if(!sti.count(s))
        {
            sti[s] = id;
            its[id ++ ] = s;   
        }
        enemy[sti[s]] = v;
    }
    while(m -- )
    {
        cin >> s >> ss >> v;
        if(!sti.count(s))
        {
            sti[s] = id;
            its[id ++ ] = s;   
        }
        if(!sti.count(ss))
        {
            sti[ss] = id;
            its[id ++ ] = s;   
        }
        add(sti[s], sti[ss], v);
        add(sti[ss], sti[s], v);
    }
    
    djikstra(hh);
    
    out(tt);
    cout << endl << path[tt] << " " << dist[tt] << " " << kill[tt] << endl;
    
    return 0;
}