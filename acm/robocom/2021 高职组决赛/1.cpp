#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

const int N = 110;

int n, m, k;
string s[N];
int w[N][N];
unordered_map<int, int> mp;

int main()
{
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; i ++ )
    {
        string str;
        getline(cin, str);
        s[i] = str;
    }
    
    // for(int i = 0; i < n; i ++ )    cout << s[i] << endl;

    for (int i = 1; i <= m; i ++ )
    {
        int x;
        cin >> x;
        mp[x] = i;
    }

    for (int i = 1; i <= m; i ++ )
        for(int j = 0; j < 10; j ++ )
            cin >> w[i][j];
    
    cin >> k;
    while(k -- )
    {
        int t;
        cin >> t;
        int x = t / 10, y = t % 10;
        x = mp[x];
        // cout << "pos: " << t << ' ' << x << ' ' << y << ' ' << w[x][y] << endl;
        if(w[x][y] == -1 || x == 0)   cout << "?" << endl;
        else cout << s[w[x][y]] << endl;
    }
    
    
    return 0;
}