#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, st;
PII w[N];
vector<int> res, more;
set<int> s;

int main()
{
    cin >> st >> n;
    for(int i = 0; i < n; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        w[a] = {b, c};
    }
    
    for(int i = st; i != -1; i = w[i].y)
    {
        if(!s.count(abs(w[i].x)))
        {
            s.insert(abs(w[i].x));
            res.push_back(i);
        }   
        else
        {
            more.push_back(i);
        }
    }
    
    
    for(int i = 0; i < res.size(); i ++ )
    {
        int t = res[i];
        if(i != res.size() - 1)    printf("%05d %d %05d\n", t, w[t].x, res[i + 1]);
        else    printf("%05d %d %d\n", t, w[t].x, -1);
    }
    
    for(int i = 0; i < more.size(); i ++ )
    {
        int t = more[i];
        if(i != more.size() - 1)    printf("%05d %d %05d\n", t, w[t].x, more[i + 1]);
        else    printf("%05d %d %d\n", t, w[t].x, -1);
    }
    
    
    
    return 0;
}