#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010, M = 20010, INF = 0x3f3f3f3f;

int n, m, k, limit_dist, dist[N];;
int res_Alldist, res_Mindist, res_id;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];

int get(string s)
{
    int num = 0;
    if(s[0] == 'G') //垃圾箱
    {
        for(int i = 1; s[i]; i ++ ) num = num * 10 + s[i] - '0';
        num += n;   //垃圾箱的编号+n
    }
    else
        for(int i = 0; s[i]; i ++ ) num = num * 10 + s[i] - '0';

    return num;
}

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa(int id)
{
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(id);
    st[id] = true, dist[id] = 0;
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    bool flag = true;
    int tmp_Alldist = 0, tmp_Mindist = INF;
    for(int i = 1; i <= n; i ++ )
    {
        if(dist[i] > limit_dist) //如果居民点与垃圾箱的距离超过限制距离
        {
            flag = false;
            break;
        }
        else
        {
            tmp_Mindist = min(tmp_Mindist, dist[i]);
            tmp_Alldist += dist[i];
        }
    }
    
    //flag=true确保居民点与垃圾箱之间的距离没有超过最大距离
    //如果(当前最短距离)大于(答案最短距离)
    //或者(当前最短距离)等于(答案最短距离)，并且(当前总长度)小于(答案总长度)
    //因为我们是从小到大以此枚举垃圾桶，所以不需要考虑最大距离相同，总距离相同的情况
    if(flag && ((tmp_Mindist > res_Mindist) || (tmp_Mindist == res_Mindist && tmp_Alldist < res_Alldist)))
    {
        res_id = id;
        res_Mindist = tmp_Mindist;
        res_Alldist = tmp_Alldist;
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k >> limit_dist;
    while(k -- )
    {
        int a, b, c;
        string s1, s2;
        cin >> s1 >> s2 >> c;
        a = get(s1), b = get(s2);
        add(a, b, c); add(b, a, c);
    }
    
    for(int i = 1; i <= m; i ++ )   spfa(i + n);
    
    if(!res_id) puts("No Solution");
    else
    {
        printf("G%d\n", res_id - n);
        printf("%.1f %.1f\n", 1.0 * res_Mindist, 1.0 * res_Alldist / n);
    }
    return 0;
}