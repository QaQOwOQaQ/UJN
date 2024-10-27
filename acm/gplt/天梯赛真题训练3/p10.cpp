#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010;

int a[N], q[N];
int n, cnt;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++)
    {
        int l = 0, r = cnt;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(a[i] < q[mid]) r = mid;
            else l = mid + 1;
        }
        if(r < cnt) q[r] = a[i];
        else q[cnt ++ ] = a[i];
    }
//     for(int i = 0; i < cnt; i ++ )  cout << q[i] << " ";
    cout << cnt << endl;
    return 0;
}
