#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 110;

int pre[N];
int n, m, k;
set<int> s[N];

void init()
{
    for(int i = 0; i < N; i ++ )    pre[i] = i;
}

int find(int x)
{
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    pre[fx] = fy;
}

void relation(int a, int b)
{
    if(find(a) == find(b))  //有共同朋友
    {
        if(s[a].count(b))    cout << "OK but...";
        else    cout << "No problem";
    }
    else    //没有共同朋友
    {
        if(s[a].count(b))  cout << "No way";
        else    cout << "OK";
    }
    cout << endl;
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 1)
        {
            join(a, b);
        }
        else    //c == -1
        {
            s[a].insert(b);
            s[b].insert(a);
        }
    }
    
    for(int i = 0; i < k; i ++ )
    {
        int a, b;
        cin >> a >> b;
        relation(a, b);
    }
    
    return 0;
}