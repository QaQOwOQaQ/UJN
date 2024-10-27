#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, last, now;
bool st[N][N], vis[N][N];
char g[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(int x, int y)
{
    last ++ ;
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    bool flag = false;
    while(q.size())
    {
        auto t = q.front();     q.pop();
        bool has_land = true;
        for(int i = 0; i < 4; i ++ )
        {
            int xx = t.first + dx[i], yy = t.second + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= n || st[xx][yy])  continue;
            if(g[xx][yy] == '.')    
            {
                has_land = false;
                continue;
            }
            q.push({xx, yy});
            st[xx][yy] = true;
        }
        if(has_land)    flag = true;
    }
    if(flag)    now ++ ;
}

bool check(int x, int y)
{
    for(int i = 0; i < 4; i ++ )
    {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= n || g[xx][yy] == '#')    continue;
        return true;
    }
    return  false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        string s;   cin >> s;
        for(int j = 0; j < n; j ++ )
            g[i][j] = s[j];
    }
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            if(g[i][j] == '#' && !st[i][j])
                bfs(i, j);
        
    
    // cout << last << " " << now << endl;
    cout << last - now << endl;
    return 0;
}

/*输出3
10
..........
.##.......
.##.......
....##.#..
..#######.
...###.#..
..........
..#....#..
......###.
..........
*/
