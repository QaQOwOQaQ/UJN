// 简单排序
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int n;

struct node_t {
    int id = 0;
    int sum = 0;
    int count = 0;
} node[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int k;  cin >> k;
        node[i].id = i;
        while(k -- )
        {
            int id;
            int p;
            cin >> id >> p;
            node[i].sum -= p;
            node[id].sum += p;
            node[id].count ++ ;
        }
    }
    sort(node + 1, node + 1 + n, [&](const node_t &l, const node_t &r){
        if(l.sum == r.sum) 
        {
            if(l.count == r.count)  return l.id < r.id;
            return l.count > r.count;
        }
        return l.sum > r.sum;
    });
    
    for(int i = 1; i <= n; i ++ )
    {
        printf("%d %.2lf\n", node[i].id, node[i].sum * 1.0 / 100);
    }
    return 0;
}