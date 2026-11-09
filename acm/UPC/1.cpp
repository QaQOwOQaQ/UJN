#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double a0,a1,ann,c[3010];
        int i,sum=0;
        scanf("%lf%lf",&a0,&ann);
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&c[i]);
            sum+=c[i]*(n+1-i);
        }
        a1=(n*a0+ann-2*sum)/(n+1);
        printf("%.2lf\n",a1);
    }
    return 0;
}

