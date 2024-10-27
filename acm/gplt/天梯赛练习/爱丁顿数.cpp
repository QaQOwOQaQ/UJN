#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, w[N];

bool check(int x)
{
    int cnt = 0, last = 0;
    for(int i = 0; i < n; i ++ )
        if(w[i] > x)    
            cnt ++ ;
            
    return cnt >= x;
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> w[i];
    
    int l = 0, r = n;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid))  l = mid;
        else r = mid - 1;
    }
    
    cout << l << endl;

    
    return 0;
}