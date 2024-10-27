#include <iostream>
#include <string>
using namespace std;
const int M=10000+100;
string s[110];
int fa[M];
int get(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
    fa[get(x)]=get(y);
}
int main()
{
    for(int i=0;i<M;i++)
        fa[i]=i;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                if(s[i+1][j]=='#')
                    merge(i*m+j,(i+1)*m+j);
                if(s[i][j+1]=='#')
                    merge(i*m+j,i*m+j+1);
            }
        }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int num=i*m+j;
            if(fa[num]==num&&s[i][j]=='#')
                cnt++;
        }
    cout<<cnt<<endl;
    return 0;
}
/*
5 6
....S*
.**...
.*..*.
*..**.
.T....
*/