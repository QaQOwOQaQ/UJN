//21:50
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010, M = 1010;

int backup[M];//存档点
vector<int> v[N];
vector<int> res;
int n, m, nowpos;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        v[i].push_back(0);  //下面的指令是从1开始的
        int k;  cin >> k;
        while(k -- )
        {
            int x;  cin >> x;
            v[i].push_back(x);
        }
    }
    
    nowpos = 1; //当前剧情点
    while(m -- )
    {
        int op, k;
        cin >> op >> k;
        if(op == 0) //move
        {
            nowpos = v[nowpos][k];
        }
        else if(op == 1)//存档
        {
            backup[k] = nowpos;
            res.push_back(nowpos);
        }
        else//读取存档
        {
            nowpos = backup[k];
        }
    }
    
    res.push_back(nowpos);
    for(auto &x : res)  cout << x << endl;
    
    return 0;
}