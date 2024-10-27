#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

const int N = 10010;

int n, m, a[N], idx;
set<string> S;
map<string, int> si;
map<string, vector<int> > sv;
map<int, string> is;

struct Node{
    int sum;
    vector<int> v;
}node[N];

bool cmp(Node x, Node y)
{
    if(x.sum == y.sum)  return x.v < y.v;
    return x.sum > y.sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++ )
    {
        string s = "";
        for(int j = 1; j <= m; j ++ )
        {
            scanf("%d", &a[j]);
            s += to_string(a[j]);
        }
        
        //cout << s << endl;
        
        if(S.count(s))   si[s] ++ ;
        else
        {
            si[s] = 1;
            is[idx ++ ] = s;
            S.insert(s);
            for(int j = 1; j <= m; j ++ )   sv[s].push_back(a[j]);   
        }
    }

    for(int i = 0; i < idx; i ++ )
    {
        string str = is[i];
        node[i] = {si[str], sv[str]};
    }
    sort(node, node + idx, cmp);
    
    printf("%d\n", idx);
    for(int i = 0; i < idx; i ++ )
    {
        printf("%d ", node[i].sum);
        for(int j = 0; j < node[i].v.size(); j ++ )
        {
            printf("%d", node[i].v[j]);
            if(j != node[i].v.size() - 1)   printf(" ");
        }
        puts("");
    }
    
    return 0;
}