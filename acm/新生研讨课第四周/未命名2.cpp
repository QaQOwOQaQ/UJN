
# include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, icount, flag[103], vis[30];
    char s[103];
    while(~scanf("%d%s",&k,s))
    {
        icount = 0;
        memset(flag, 0, sizeof(flag));
        memset(vis, 0, sizeof(vis));
        int len = strlen(s);
        if(k > len)
        {
            puts("NO");
            continue;
        }
        for(int i=0; i<len&&icount<k; ++i)
        {
            int n = s[i]- 'a';
            if(!vis[n])
            {
                vis[n] = 1;
                flag[i] = 1;
                ++icount;
            }
        }
        if(icount != k)
        {
            puts("NO");
            continue;
        }
        puts("YES");
        putchar(s[0]);
        for(int i=1; i<len; ++i)
        {
            if(flag[i] == 1)
                printf("\n");
            putchar(s[i]);
        }
        printf("\n");
    }
    return 0;
}
