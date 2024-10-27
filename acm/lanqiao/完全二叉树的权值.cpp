#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, a[N];
LL s[N];

inline int get(int x)
{
    int d = 0;
    while(x)
    {
        d ++ ;
        x /= 2;
    }
    return d;
}

inline int getst(int x)
{
    int res = 1;
    for(int i = 1; i <= x - 1; i ++ )   res *= 2;
    return res;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   
    {
        cin >> a[i];
        s[i] = (LL)s[i - 1] + a[i];
    }
    int depth = get(n);
 //   cout << "depth: " << depth << endl;
    
    LL maxn = -1, pos = -1;
    for(int i = 1; i <= depth; i ++ )
    {
        int st = getst(i), end = getst(i + 1);
     //   cout << "pos: " << st << " " << end - 1 << " ";
        LL t = s[min(n, end - 1)] - s[st - 1];
      //  cout << "t: " << t << endl;
        if(t > maxn)
        {
            pos = i;
            maxn = t;
        }
    }
    cout << pos << endl;
    return 0;
}