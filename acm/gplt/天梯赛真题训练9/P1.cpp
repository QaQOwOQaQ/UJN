//14：45
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<int> res;
set<int> s;
bool st[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int k, en, be;  
        cin >> k;
        if(!k)  continue;
        cin >> be;
        for(int j = 0; j < k - 1; j ++ )
        {
            cin >> en;
            if(en != be)
            {
                st[en] = true;
                st[be] = true;
            }
        }
    }
    cin >> m;
    while (m -- )
    {
        int x;  cin >> x;
        if(!st[x])  
        {
            if(!s.count(x)) res.push_back(x), s.insert(x);
        }
    }
    
    for(int i = 0; i < res.size(); i ++ )
    {
        printf("%05d", res[i]);
        if(i != res.size() - 1) printf(" ");
    }
    if(res.size() == 0) puts("No one is handsome");
    
    
    return 0;
}