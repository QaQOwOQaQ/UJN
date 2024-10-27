#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, a[N];

int main()
{
    int n;  cin >>n;
    for(int i = 0; i <n; i ++ ) cin >> a[i];
    sort(a, a + n, greater<int>() );
    cout << a[0] << endl;
    
    return 0;
}