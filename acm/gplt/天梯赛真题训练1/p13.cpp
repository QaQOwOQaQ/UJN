// 两个像素被认为是“连通的”，如果它们有一个共同的切面 ---> 显然本题是三维bfs。

// 判断到一个肿瘤像素1时，搜索出最大连通数目即面积，同时把搜索过的部分变成0表示已记过数，最后连通块面积如果不小于t则计入总数。
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, l, t;
int res;
bool g[1300][130][60];	//定义成bool(1个字节) , int则是4个字节 
struct point{
    int x, y, z;    
};
//定义六个方向的偏移矩阵 
int dx[6][3] = {
    {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}
};

void bfs(int x, int y, int z)
{
    queue<point> q;
    q.push({x, y, z});
    g[x][y][z] = 0;
    
    int cnt = 0;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        cnt ++ ;
        for(int i = 0; i < 6; i ++ )
        {
            x = t.x + dx[i][0];
            y = t.y + dx[i][1];
            z = t.z + dx[i][2];
            if(x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < l && g[x][y][z])
            {
                g[x][y][z] = 0;
                q.push({x, y, z});
            }
        }
    }
    if(cnt >= t)    res += cnt;
}

int main()
{
    cin >> m >> n >> l >> t;
    for(int h = 0; h < l; h ++ )//高度即第三维放在最外层 
        for(int i = 0; i < m; i ++ )
            for(int j = 0; j < n; j ++ )
                cin >> g[i][j][h];
                
     for(int h = 0; h < l; h ++ )   //爆搜BFS
        for(int i = 0; i < m; i ++ )
            for(int j = 0; j < n; j ++ )
                if(g[i][j][h])
                    bfs(i, j, h);
        
    
    cout << res << endl;
    
    return 0;
}