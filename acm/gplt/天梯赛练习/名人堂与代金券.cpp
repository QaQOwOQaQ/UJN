#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<string, int> PSI;

const int N = 10010;

int n, g, k, res;
PSI w[N];

bool cmp(PSI a, PSI b)
{
    if(a.y == b.y)  return a.x < b.x;
    return a.y > b.y;
}

int main()
{
    cin >> n >> g >> k;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> w[i].x >> w[i].y;
        if(w[i].y >= 60 && w[i].y < g)  res += 20;
        else if(w[i].y >= g && w[i].y <= 100)   res += 50;
    }
    
    sort(w + 1, w + n + 1, cmp);
    
    cout << res << endl;
    int last = -1, cnt = 0, tmp = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(last == -1 || w[i].y < last) //new num
        {
            last = w[i].y;
            cnt ++ ;
            cnt += tmp;
            tmp = 0;
        }  
        else    //old num
        {
            tmp ++ ;
        }
        if(cnt > k) break;
        cout << cnt << " " << w[i].x << " " << w[i].y << endl;
    }
    
    
    
    return 0;
}