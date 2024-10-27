#include <iostream>

using namespace std;

const int N = 110;

int n, m;
int w[N], s[N], res[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++ )   cin >> w[i];
    for(int i = 1; i <= m; i ++ )   cin >> res[i];
    
    for(int i = 1; i <= n; i ++ )
    {
        int sum = 0;
        for(int j = 1; j <= m; j ++ )
        {
            int x;  cin >> x;
            sum += res[i] * (x == res[j]);
        }
        cout << sum << endl;
    }
}