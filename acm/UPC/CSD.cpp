
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
    int deadline;
	int score;
    
}a[1002];
 
int IsDone[2000];
 
bool cmp(node a,node b)
{
	return a.score>b.score;
}
 
 
int main()
{
    int Case,n;
    cin>>Case;
    while(Case--)
    {
        memset(IsDone,0,sizeof(IsDone));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].deadline;
        for(int i=1;i<=n;i++)
            cin>>a[i].score;
        sort(a+1,a+n+1,cmp);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            for(int j=a[i].deadline;j>=1;j--)
            {
                if(!IsDone[j])
                {
                    IsDone[j]=1;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            sum+=a[i].score;
        }
        cout<<sum<<endl;
    }
    return 0;
}


