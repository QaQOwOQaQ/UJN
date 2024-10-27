#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100;

int n;
bool st[N], w[N][N];
vector<int> res, path;

bool check()
{
    for(int i = 1; i <= n; i ++ )
        if(!st[i] && w[i][1] == 1)    
            return true;
    return false;
}

void dfs(int u, vector<int> path)
{
    if(path.size() == n - 1)   //答案搜索完毕
    {
        res = path;
        return ;
    }
    if(res.size())  return ;
    if(!check())   return ;    //没有战胜的球队
   
   
    for(int i = 1; i <= n; i ++ )
    {
        if(!st[i] && w[u][i])   //如果该节点没有访问过并且合法
        {
            st[i] = true;   //标记
            path.push_back(i);  //加入答案
            dfs(i, path);   //往下dfs
            //回溯
            st[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        string s;   cin >> s;
        for(int j = 0; j < s.length(); j ++ )
        {
            if(s[j] == 'W') w[i][j + 1] = 1;
            if(s[j] == 'L') w[j + 1][i] = 1;
        }
    }
    
    st[1] = true;
    dfs(1, path);
    if(!res.size())    puts("No Solution");
    else
    {
        cout << 1 << " ";
        for(int i = 0; i < res.size(); i ++ )
        {
            cout << res[i];
            if(i != res.size() - 1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
//1 3 5 4 2