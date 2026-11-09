#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010; 

int h[N], e[N], ne[N], w[N], idx;
int dist[N], n, m;
bool st[N];

void add(int a, int b, int c)   //邻接表存贮的都是顶点下标
{
    w[idx] = c; //放在idx++前面   
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa()
{
    //最短路初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    //队列初始化,注意存放的是顶点而不是顶点下标
    queue<int> q;
    q.push(1);
    st[1] = true;   //标记入队
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();    //队头取出来当然要删除
        
        st[t] = false;  //标记出队
        
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];   //得到顶点 
            if(dist[j] > dist[t] + w[i]) //区分这里下标j,t,i的含义
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])  //可以入队
                {
                    q.push(j);
                    st[j] = true;   //标记入队
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);    //邻接表初始化
    
    for(int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);   //邻接表不需要考虑重边和自环
    }
    
    spfa();
    
    if(dist[n] == 0x3f3f3f3f)   cout << "impossible" << endl;
    else    cout << dist[n];
    
    return 0;
}
