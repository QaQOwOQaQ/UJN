#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, pre[N];

int find(int x)
{
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

int main()
{
    for(int i = 0; i < N; i ++ )    pre[i] = i;
   
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;  cin >> x;
        int root = find(x);
        cout << root << ' ';
        pre[root] = root + 1;
    }

    return 0;
}