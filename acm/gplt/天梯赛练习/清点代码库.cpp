#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

#define x first
#define y second

using namespace std;

const int N = 10010;

typedef pair<int, vector<int> > PIS;

int n, m, idx, num[110];
set<string> S;
map<string, int> si;
PIS p[N];

bool cmp(PIS a, PIS b)
{
    if(a.x == b.x)  return a.y < b.y;
    return a.x > b.x; 
}

/*
bool cmp(PIS a, PIS b)
{
    if(a.x!=b.x)
        return a.x>b.x;
   else
   {
       for(int i=0;i<m;i++)
       {
           if(a.y[i != b.y[i]])
           return a.y[i] < b.y[i]
       }
   }
}
*/

int main()
{
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < n; i ++ )
    {
        string s = "";
        for(int j = 0; j < m; j ++ )
        {
            scanf("%d", &num[j]);
            string t = " " + to_string(num[j]); //测试点2
            s += t;
        }
        
        if(!S.count(s))
        {
            S.insert(s);
            p[idx].x ++ ;
            for(int j = 0; j < m; j ++ )    p[idx].y.push_back(num[j]);
            si[s] = idx ++ ;
        }
        else    p[si[s]].x ++ ;
    }
    
    sort(p, p + idx, cmp);
    
    printf("%d\n", idx);
    for(int i = 0; i < idx; i ++ )
    {
        printf("%d", p[i].x);
        for(int j = 0; j < m; j ++ )    printf(" %d", p[i].y[j]);
        puts("");
    }
    
    return 0;
}