#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, ne, c, sta, address;
int q[N];
pair<int, int> a[N], d[N];

int main()
{
    cin >> sta >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> address >> c >> ne;
        a[address] = {c, ne};
        d[c] = {address, ne};
    }
    
    int idx = 0;
    for(int i = sta; i != -1; i = a[i].second)
        q[++ idx] = a[i].first;

    n = idx;
    /*
    这道题的测试点3有点坑，有多余结点
    即始输入的N个结点中有多个结点的next为-1，所以还得用一个变量n来记录实际结点的个数
    不能直接用N来输出。
    */
    // for(int i = 1; i <= n; i ++ )    cout << q[i] << " ";
    
    if(n % 2 == 0)
    {
        for(int i = 1, j = n; i <= n / 2; i ++, j -- )
        {
            printf("%05d %d %05d\n", d[q[j]].first, q[j], d[q[i]].first);
            if(i == n / 2) printf("%05d %d %d\n", d[q[i]].first, q[i], -1); 
            else printf("%05d %d %05d\n", d[q[i]].first, q[i], d[q[j - 1]].first); 
        } 
    }
    else
    {
        for(int i = 1, j = n; i <= n / 2; i ++, j -- )
        {
            printf("%05d %d %05d\n", d[q[j]].first, q[j], d[q[i]].first);
            printf("%05d %d %05d\n", d[q[i]].first, q[i], d[q[j - 1]].first); 
        } 
        printf("%05d %d %d\n", d[q[n / 2 + 1]].first, q[n / 2 + 1], -1); 
    }
    
    return 0;
}