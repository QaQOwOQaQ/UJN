#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;

int n, w[N], m;
vector<int> g[N];

void dfs()
{

}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   cin >> w[i];
    
    cin >> m;
    for(int i = 1; i <= m; i ++ )
    {
        int k;  cin >> k;
        while(k -- )
        {
            int x;  cin >> x;
            g[i].push_back(x);
        }
    }
    
    dfs();
    
    return 0;
}