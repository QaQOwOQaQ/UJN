#include<bits/stdc++.h>
#include <cmath>


using namespace std;

const int maxn = 105;
int x[maxn],y[maxn];
double p[maxn],ans;
int n;

int cj(int x1,int y1,int x2,int y2)
{
    return (x1 * y2 - y1 * x2);
}
signed main()
{
    cin >> n;
    for(int i = 1;i <= n; i++)
        scanf("%d%d%lf", &x[i], &y[i], &p[i]);
    double s = 0;
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            if(i != j)
            {
                s = p[i] * p[j] * cj(x[i],y[i],x[j],y[j]);
                for(int k = 1;k <= n; k++)
                {
                    if(k != i && k != j)
                    {
                        if(cj(x[k] - x[i],y[k] - y[i],x[j] - x[i],y[j] - y[i]) <= 0)
                            s -= (double)p[k] * s;
                    }
                }
                ans += s;
            }
        }
    }
    printf("%.6lf", fabs(ans / 2));
    return 0;
}