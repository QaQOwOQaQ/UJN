#include <iostream>
#include <cstring>
#include <ctime>
#include <set>
 
using namespace std;

const int N = 15;

int res;
int g[N][N];
int a[12] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
//第一种dfs方式
void dfs(int i, int j){
    g[i][j] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    for (int k = 0; k < 4; k ++ ){
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < 3 && y >= 0 && y < 4 && g[x][y] == 1)
            dfs(x, y);
    } 
}
bool check(){
    for (int i = 0; i < 3; i ++ )
        for (int j = 0; j < 4; j ++ )
            if (a[i * 4 + j] == 1) g[i][j] = 1;
            else g[i][j] = 0;
    
    int cnt = 0;
    for (int i = 0; i < 3; i ++ )
        for (int j = 0; j < 4; j ++ )
            if (g[i][j] == 1){
                dfs(i, j);
                cnt ++;
            }
            
    return cnt == 1;
}

set<string> s1;

void a2s(string &s){
    for (int i = 0; i < 12; i ++ )
        s.insert(s.end(), a[i] + '0');
}

bool isExist(){
    string a_str;
    a2s(a_str);
    if (s1.find(a_str) == s1.end()){
        s1.insert(a_str);
        return false;
    }else return true;
}
void df(int u){
    if (u == 12){
        if (!isExist() && check()) res ++;
        return;
    }
    
    for (int i = u; i < 12; i ++ ){
        swap(a[i], a[u]);
        df(u + 1);
        swap(a[i], a[u]);
    }
}

int main(){
    df(0);
    
    cout << res << endl;
    cout << clock() << "ms" << endl;
    return 0;
}





















/*wrong!!!
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 100;

int w[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
int dx[8] = {
    1, -1, 0, 0, 1, 1, -1, -1
};
int dy[8] = {
    0, 0, 1, -1, -1, 1, -1, 1
};
set<string> s;
bool st[10][10];

void dfs(int x, int y, vector<int> v)
{
    if(v.size() == 5)
    {
        string res = "";
        sort(v.begin(), v.end());
        for(auto &x : v) res += to_string(x) + "***";
        s.insert(res);
        return ;
    }
    if(v.size() > 5)    return ;
    for(int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || b < 0 || a >= 3 || b >= 4 || st[a][b])  continue;
        v.push_back(w[a][b]);
        st[a][b] = true;
        
        dfs(a, b, v);
        
        st[a][b] = false;
        v.pop_back();
    }
}

int main()
{
    //max = 792
    for(int i = 0; i < 3; i ++ )
        for(int j = 0; j < 4; j ++ )
        {
            memset(st, 0, sizeof st);
            vector<int> v;
            dfs(i, j, v);
        }
    cout << s.size() << endl << endl;
    for(auto &x : s)    cout << x << endl;

    return 0;
}
*/