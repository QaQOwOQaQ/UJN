#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100;

int w[N][N], n;
int res[N];
bool has_answer, st[N];

bool check()
{
    for(int i = 2; i <= n; i ++ )
        if(!st[i] && w[i][1]) return true;
    return false;
}

void dfs(int u)
{
    if(u > n)
    {
        for(int i = 1; i <= n; i ++ )
        {
            cout << res[i];
            if(i != n)  cout << " ";
        }
        cout << endl;
        has_answer = true;
        return ;
    }
    if(has_answer)  return ;
    if(!check())    return ;
    
    for(int i = 1; i <= n; i ++ )
    {
        if(!st[i] && w[res[u - 1]][i] == 1 && check())
        {
            st[i] = true;
            res[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
    }
    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        string s;   cin >> s;
        for(int j = 0; j < s.size(); j ++ )
        {
            if(s[j] == 'W') w[i][j + 1] = 1;
            else if(s[j] == 'L') w[j + 1][i] = 1;
        }
    }

    // for(int i = 1; i <= n; i ++ )
    // {
    //     for(int j = 1; j <= n; j ++ )   cout << w[i][j] << " ";
    //     cout << endl;
    // }
    
    res[1] = 1;
    st[1] = true;
    dfs(2);
    if(!has_answer)   puts("No Solution");

    return 0;
}