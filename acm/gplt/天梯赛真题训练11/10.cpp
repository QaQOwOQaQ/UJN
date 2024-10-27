#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const double eps = 1e-6;
const int N = 10010;

int n, in[N];
double w[N];
struct node{
    double num = 0;
    int cnt = 0;
    int id;
}p[N];

bool cmp(node a, node b)
{
    if(a.num == b.num)
    {
        if(a.cnt == b.cnt)  return a.id < b.id;
        return a.cnt > b.cnt;
    }
    return a.num > b.num;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int k;  cin >> k;
        while(k -- )
        {
            int id;
            double money;
            cin >> id >> money;
            w[id] += money;
            w[i] -= money;
            in[id] ++ ;
        }
    }
    
    for(int i = 1; i <= n; i ++ )
    {
        p[i].num = w[i] / 100;
        p[i].cnt = in[i];
        p[i].id = i;
    }
        
    sort(p + 1, p + 1 + n, cmp);
    
    for(int i = 1; i <= n; i ++ )
        printf("%d %.2lf\n", p[i].id, p[i].num);
    
    
    return 0;
}