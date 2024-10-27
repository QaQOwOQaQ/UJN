#include<bits/stdc++.h>

#define int long long
#define debug(x) cerr<<#x<<" = "<<x<<endl

using namespace std;

const int maxn=1e5+10;

int a[maxn],ans[maxn],all[maxn];
vector<pair<int,int> >G[maxn];
map<int,int>m[maxn];

void dfs(int u,int f)
{
    for(auto k : G[u])
    {
        int v=k.first,id=k.second;
        if(v==f) continue;
        dfs(v,u); 
        int now=1,kk=-1;
        for(auto t:m[v])
        {
            int tmp=min(all[t.first]-t.second,t.second);
            if(tmp>now||tmp==now&&t.first>kk)
            {
                now=tmp;
                kk=t.first;
            }
            m[u][t.first]+=t.second;
        }
        m[v].clear();
        ans[id]=kk;
    }
    m[u][a[u]]++;
}

signed main()
{
    ios::sync_with_stdio(false);

    int n;  cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],all[a[i]]++;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        G[u].push_back({v,i});
        G[v].push_back({u,i});
    }
    dfs(1,-1);
    for(int i=1;i<n;i++) cout<<ans[i]<<"\n";
}
