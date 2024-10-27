#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 100010;

int n, m, idx;
unordered_set<string> S;
string s[N], res[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> s[i];
    cin >> m;
    for(int i = 0; i < m; i ++ )
    {
        string str;
        cin >> str;
        S.insert(str);
    }
    
    for(int i = 0; i < n; i ++ )
        if(!S.count(s[i]))
            res[idx ++ ] = s[i];
    
    sort(res, res + idx, greater<string>());
    for(int i = 0; i < idx; i ++ )  cout << res[i] << endl;
    
    return 0;
}