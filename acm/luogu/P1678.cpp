#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int q[N];

int findl(int x)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(q[mid] >= x) r = mid;
        else    l = mid + 1;
    }
    return l;
}

int findr(int x)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(q[mid] <= x) l = mid;
        else    r = mid - 1;
    }
    return l;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )    cin >> q[i];
    sort(q, q + n);
    long long res = 0;
    while (m -- )
    {
        int x;  cin >> x;
        int l = findl(x);
        int r = findr(x);
        res += min(abs(x - q[l]), abs(x - q[r]));
    }
    cout << res << endl;
    return 0;
}