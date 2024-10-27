/*
还是细节决定成败
对于三个数ax,ay,az
题目并没有说x，y，z的关系，所以这三个数可以任意选！！
我之前还傻乎乎的排序做，哎。。。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 100100;

int n, a[N], cnt[N];
bool st[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> a[i], cnt[a[i]] ++ ;
    
    long long sum = 0, res = 0;
    for(int i = 1; i < N; i ++ )
    {
        if(cnt[i] > 1)  sum += cnt[i] - 1;
    }
    
    res = (sum+1) / 2;
    cout << res << endl;
    
    
    return 0;
}
/*
1 2 2 2 3 4 5
1 1 2 3 3 4 5
*/