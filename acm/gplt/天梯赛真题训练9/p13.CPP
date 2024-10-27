#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 1000010;

int n, m, start, en;
int h[N], e[M], ne[M], ts[M], ds[M], idx;
int dist[N], times[N];
int cnt[N];//cnt数组用来记录途径节点个数
int pre[N];//pre用来标记一个节点的前驱
bool st[N];
vector<int> res_dist, res_time;
int mp[N][N], tdist[N];//用于时间相同时判断距离

void add(int a, int b, int d1, int d2)
{
    ts[idx] = d2, ds[idx] = d1;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra1()//time
{
    memset(times, 0x3f, sizeof times);
    memset(st, 0, sizeof st);
    memset(pre, -1, sizeof pre);
    memset(tdist, 0, sizeof tdist);
    
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, start});
    times[start] = 0;
    tdist[start] = 0;
    
    while(q.size())
    {
        auto t = q.top();   q.pop();
        int ver = t.second, Alltimes = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(times[j] > Alltimes + ts[i])
            {
                times[j] = Alltimes + ts[i];
                q.push({times[j], j});
                pre[j] = ver;
                tdist[j] = tdist[ver] + mp[ver][j];
            }
            else if(times[j] == Alltimes + ts[i])
            {
                if(tdist[j] > tdist[ver] + mp[ver][j])
                {
                    q.push({times[j], j});
                    tdist[j] = tdist[ver] + mp[ver][j];
                    pre[j] = ver;
                }
            }
        }
    }
    
}

void dijkstra2()//dist
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(pre, -1, sizeof pre);
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, start});
    dist[start] = 0;
    cnt[start] = 1;
    while(q.size())
    {
        auto t = q.top();   q.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + ds[i])
            {
                dist[j] = distance + ds[i];
                cnt[j] = cnt[ver] + 1;
                pre[j] = ver;
                q.push({dist[j], j});
            }
            else if(dist[j] == distance + ds[i])//如果最短路相等
            {
                if(cnt[j] > cnt[ver] + 1)//找路径城市最少的
                {
                    cnt[j] = cnt[ver] + 1;
                    pre[j] = ver;
                    q.push({dist[j], j});
                }
            }
        }
    }
}

vector<int> out(int tt)
{
    vector<int> res;
    while(tt != -1)    
    {
        res.push_back(tt);
        tt = pre[tt];
    }
    return res;
}

int main()
{
    memset(mp, 0x3f, sizeof mp);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m -- )
    {
        int a, b, op, d1, d2;
        cin >> a >> b >> op >> d1 >> d2;
        add(a, b, d1, d2);
        mp[a][b] = d1;
        if(!op) add(b, a, d1, d2), mp[b][a] = d1;
    }
    
    cin >> start >> en;
    
    dijkstra2();  
    res_dist = out(en);    
    
    dijkstra1();
    res_time = out(en);


    if(res_time == res_dist)
    {
        printf("Time = %d; Distance = %d: ", times[en], dist[en]);
        for(int i = res_time.size() - 1; i >= 0; i -- )
        {
            cout << res_time[i];
            if(i != 0)  cout << " => ";
        }
        cout << endl;
    }
    else
    {
        printf("Time = %d: ", times[en]);
        for(int i = res_time.size() - 1; i >= 0; i -- )
        {
            cout << res_time[i];
            if(i != 0)  cout << " => ";
        }
        cout << endl;
        printf("Distance = %d: ", dist[en]);
        for(int i = res_dist.size() - 1; i >= 0; i -- )
        {
            cout << res_dist[i];
            if(i != 0)  cout << " => ";
        }
        cout << endl; 
    }
    
    return 0;
}