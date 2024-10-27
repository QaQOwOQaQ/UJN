/*
    二分做法
    O(NlogN)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define debug1(var) \
    cout << #var << " = " << var << endl 
#define debug(var1, var2) \
    cout << #var1 << " = " << var1 << " " << #var2 << " = " << var2 << endl  
    
using namespace std;

typedef long long LL;

const int N = 1000010;

LL n, a, b, res;
LL zero[N], one[N];
char s[N];
//zero->can play->a
bool check(LL x,LL y)
{
    if(zero[y] - zero[x - 1] >= a && 
        one[y] - one[x - 1] >= b)  
            return true;
    return false;
}

int main()
{
    cin >> n >> a >> b;
    cin >> s + 1;
    for(LL i = 1; i <= n; i ++ )
    {
        zero[i] = zero[i - 1] + (s[i] == '0');
        one[i] = one[i - 1] + (s[i] == '1');
    }
    for(LL i = 1; i <= n; i ++ )
    {
        LL l = i, r = n;
        while(l < r)//找到第一个符合的区间
        {
            LL mid = (l + r) >> 1;
            if(check(i, mid))  r = mid;
            else l = mid + 1;
        }
        if(check(i, l))    
        {
            debug(i, l);
            res += (n - l + 1);
            debug1(res);
        }
    }
    if(a == 0 && b == 0)    //需要特判一下
        res ++ ;
    cout << res << endl;
    return 0;
}

/*
尺取做法
o(N)

*/
/*
#include <iostream>
#include <cstring>
#include <algorithm>

#define debug1(var) \
    cout << #var << " = " << var << endl 
#define debug(var1, var2) \
    cout << #var1 << " = " << var1 << " " << #var2 << " = " << var2 << endl  
    
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n, a, b;
LL zero[N], one[N];
LL res;
char s[N];

bool check(int l, int r)
{
    if(r < l)   return false;//多一步判断
    if(zero[r] - zero[l - 1] >= a
        && one[r] - one[l - 1] >= b)
        return true;
    return false;
}

int main()
{
    cin >> n >> a >> b;
    cin >> s + 1;
    for(int i = 1; i <= n; i ++ )
    {
        zero[i] = zero[i - 1] + (s[i] == '0');
        one[i] = one[i - 1] + (s[i] == '1');
    }
    int st = 1, en = 1;
    for(int i = 1; i <= n; i ++ )
    {
        while(en <= n && !check(st, en))   en ++;
        if(en > n)  break;
        res += (n - en + 1);
        // debug(st, en);
        // debug1(res);
        st ++ ;
    }
    if(a == 0 && b == 0)    res ++ ;
    cout << res << endl;
    return 0;
}
*/