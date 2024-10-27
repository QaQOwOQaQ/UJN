#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

const int N = 100010;

int n, m, k;
int id[N];
unordered_map<int, int> mp;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )    cin >> id[i];
    int idx = 1;
    
    for(int i = 1; i <= n / m; i ++ )
    {
        stack<int> s;
        for(int j = 1; j <= m; j ++ )
        {
            int x;  cin >> x;
            s.push(x);
        }
        while(s.size())
        {
            mp[id[idx ++ ]] = s.top();
            s.pop();
        }
    }

    cin >> k;
    while(k -- )
    {
        int x;  cin >> x;
        if(mp[x] == 0)  puts("Wrong Number");
        else cout << mp[x] << endl;
    }
    
    
    return 0;
}

