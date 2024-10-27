#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10100;

int n, m;
struct node{
    double store;//题目并没有说库存和售价是整数！！恶心人！！不开double卡两分！
    double price;
}a[N];

bool cmp(const node &x, const node &y)
{
    return x.price * y.store > y.price * x.store; 
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )    cin >> a[i].store;
    for(int i = 0; i < n; i ++ )    cin >> a[i].price;
    
    sort(a, a + n, cmp);
    
    double res = 0;
    for(int i = 0; i < n; i ++ )
    {
        if(!m)  break;
        if(m > a[i].store)  res += a[i].price, m -= a[i].store; 
        else 
        {
            res += a[i].price * m / a[i].store;
            break;
        }
    }
    printf("%.2lf\n", res);
    
    return 0;
}