
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <ctime>
#include <cctype>
#include <bitset>
#include <utility>
#include <sstream>
#include <complex>
#include <iomanip>
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
int n,t[20010],ys[20010],sum,ct;

void db(int x)
{
    for(int i=2; i<x; i++)
        if(x%i==0)
            ys[ct++]=i;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        sum+=t[i];
    }
    db(n);
    if(n==3||ct==0)
        cout<<sum<<endl;
    else
    {
        int mx=sum;
        for(int i=0; i<ct; i++)
        {
            int ls=ys[i],tt=1;
            while(ls--)
            {
                int jg=0,js=0;
                for(int j=tt; j<=n; j+=ys[i])
                {
                    jg+=t[j];
                    js++;
                }
                if(js>=3)
                    mx=max(mx,jg);
                tt++;
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}

