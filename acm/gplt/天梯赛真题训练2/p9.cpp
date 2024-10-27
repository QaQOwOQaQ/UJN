#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, k;
struct node{
    int id = 0;
    int cnt = 0;
    double my = 0.0;
}a[N];

bool cmp(node x, node y)
{
    if(x.my == y.my)
    {
        if(x.cnt == y.cnt)  return x.id < y.id;
        return x.cnt > y.cnt;
    }
    return x.my > y.my;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   a[i].id = i;
    
    for(int i = 1; i <= n; i ++ )
    {
        cin >> k;
        double sum = 0;
        for(int j = 0; j < k; j ++ )
        {
            int x;
            double y;
            cin >> x >> y;
            a[x].cnt ++ ;
            a[x].my += y;
            sum += y;
        }
        a[i].my -= sum;
    }
    
    
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i ++ )
        printf("%d %.2f\n", a[i].id, a[i].my / 100);
    
    return 0;
}