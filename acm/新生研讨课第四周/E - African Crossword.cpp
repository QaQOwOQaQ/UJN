#include<bits/stdc++.h>
using namespace std;
int main()
{	char s[100][100];
	int p[100][100];
    int n, m;
    scanf("%d %d", &n, &m);
    //初始化字符串 

	for(int i = 0; i < n; i++) 
		scanf("%s",&s[i]); 
	//初始化一个二维数组 
    memset(p,0,sizeof(p));
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < m; j++)
		{
            int flag = 0;		//是够删去循环下的字符 
            for(int k = j+1; k < m; k++)
			{
                if(s[i][k]==s[i][j]){
                    p[i][k] = 1;
                    flag = 1;
                }
            }
            for(int k = i+1; k < n; k++)
			{
                if(s[k][j]==s[i][j])
				{
                    p[k][j] = 1;
                    flag = 1;
                }
            }
            if(flag==1) p[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < m; j++)
		{
            if(p[i][j]==0) 
				printf("%c", s[i][j]);
        }
    }
    return 0;
}

