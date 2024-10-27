#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, k, m;
double a[N];
int b[N];

bool cmp(double x, double y)
{
    return x < y;
}

int main()
{
    cin >> n >> k >> m;
    for(int i = 0; i < n; i ++ )
    {
        for(int j = 0; j < k; j ++ )    cin >> b[j];
        sort(b, b + k);
        
        int sum = 0;
        for(int j = 1; j < k - 1; j ++ )    sum += b[j];
        a[i] = 1.0 * sum / (k - 2);
    }
    // for(int i = 0; i < n; i ++ )      printf("%.3lf ", a[i]);  
    sort(a, a + n, cmp);
    for(int i = n - m; i < n; i ++ )   
    {
        printf("%.3lf", a[i]);
        if(i != n - 1)  cout << " ";
    }
    
    return 0;
}