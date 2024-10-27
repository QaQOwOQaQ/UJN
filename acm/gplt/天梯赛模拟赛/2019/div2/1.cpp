// 绝对值重复的键值结点删掉
// addr, val, next
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;

int start, n;
unordered_map<int, PII> ass;
unordered_set<int> st;
vector<PII> rep;
vector<PII> unrep;

int main()
{
    cin >> start >> n;
    for(int i = 0; i < n; i ++ )
    {
        int addr, val, ne;
        cin >> addr >> val >> ne;
        ass[addr] = {val, ne};
    }
    
    for(int i = 0; i < n; i ++ )
    {
        auto it = ass[start];
        int addr = start;
        int val = it.first;
        int ne = it.second;
        
        start = ne;
        if(st.count(abs(val)))  rep.push_back({addr, val});
        else
        {
            st.insert(abs(val));
            unrep.push_back({addr, val});
        }
    }
    
    int m = unrep.size();
    for(int i = 0; i < m; i ++ )
    {
        if(i != m - 1)
            printf("%05d %d %05d\n", unrep[i].first, unrep[i].second, unrep[i + 1].first);
        else
            printf("%05d %d %d\n", unrep[i].first, unrep[i].second, -1);
    }
    for(int i = 0; i < n - m; i ++ )
    {
        if(i != n - m - 1)
            printf("%05d %d %05d\n", rep[i].first, rep[i].second, rep[i + 1].first);
        else
            printf("%05d %d %d\n", rep[i].first, rep[i].second, -1);
    }
    
    
    return 0;
}