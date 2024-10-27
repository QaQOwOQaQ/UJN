#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

char g[11][11];
bool st[11][11];

void change(int &x, int &y)
{
    if(g[x][y] == 'U')  x -- ;
    if(g[x][y] == 'D')  x ++ ;
    if(g[x][y] == 'L')  y -- ;
    if(g[x][y] == 'R')  y ++ ;
}

bool bfs(int i, int j)
{
    int cnt = 0;
    memset(st, false, sizeof st);
    queue<PII> q;
    q.push({i, j});
    while(q.size())
    {
        auto t = q.front();   q.pop();
        cnt ++ ;
        int x = t.first, y = t.second;
        change(x, y);   
        if(x < 0 || y < 0 || x >= 10 || y >= 10)    return true;   
        q.push({x, y});
        
        if(cnt >= 1000)  return false;
 
    }
    return false;
}

int main()
{
    for(int i = 0; i < 10; i ++ )
        for(int j = 0; j < 10; j ++ )
            cin >> g[i][j];
    
    int res = 0;
    for(int i = 0; i < 10; i ++ )
        for(int j = 0; j < 10; j ++ )
            res += bfs(i, j);
        
    cout << res << endl;

    return 0;
}