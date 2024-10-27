#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
/*
绝对值重复的键值结点删掉
只有第一个绝对值等于 K 的结点被保留
所有被删除的结点须被保存在另一个链表上
*/

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int st, n, address;
int key[N], ne[N];
PII res[N], R[N];
int idx1, idx2;
set<int> s;

int main()
{
    cin >> st >> n;
    for(int i = 1; i <= n; i ++ )   
    {
        cin >> address;
        cin >> key[address] >> ne[address];
    }
    
    
    for(int i = st; i != -1; i = ne[i])
    {
        if(s.count(abs(key[i])))
        {
            R[idx2 ++ ] = {i, key[i]};
        }
        else
        {
            res[idx1 ++ ] = {i, key[i]};
            s.insert(abs(key[i]));
        }
    }
    
    
    for(int i = 0; i < idx1; i ++ )
    {
        if(i == idx1 - 1) 
            printf("%05d %0d -1\n", res[i].first, res[i].second);
        else    
            printf("%05d %0d %05d\n", res[i].first, res[i].second, res[i + 1].first);
    }
    
    for(int i = 0; i < idx2; i ++ )
    {
        if(i == idx2 - 1) 
            printf("%05d %0d -1\n", R[i].first, R[i].second);
        else    
            printf("%05d %0d %05d\n", R[i].first, R[i].second, R[i + 1].first);
    }
    
    
    return 0;
}