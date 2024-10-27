// 0
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N = 10010;

int n, m, k, idx;
struct Node{
    char name[100];
    char num[20];
    int flag;
    int h, m;
    int pid;
};
Node node[N], res[N];
set<string> s, hurt;
map<string, int> si;

bool cmp(Node x, Node y)
{
    if(x.h != y.h)  return x.h < y.h;
    else if(x.m != y.m) return x.m < y.m;
    // else return x.pid < y.pid;
}

bool check(char ch[])
{
    if(strlen(ch) != 18) return false;
    for(int i = 0; i < 18; i ++ )
    {
        if(ch[i] >= '0' && ch[i] <= '9')  continue;
        else    return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        int t, maxn, now = 0;
        cin >> t >> maxn;
        for(int j = 0; j < t; j ++ )
        {
            node[j].pid = j;
            scanf("%s %s %d %d:%d", node[j].name, node[j].num, &node[j].flag, &node[j].h, &node[j].m);
            if(check(node[j].num) && node[j].flag && !hurt.count(node[j].num))
            {
                res[idx ++ ] = node[j];
                hurt.insert(node[j].num);
            }
            
        }
        sort(node, node + t, cmp);
        
        // cout << "node: " << endl;
        // for(int j = 0; j < t; j ++ )
        //     printf("%s %s %d %d:%d\n", node[j].name, node[j].num, node[j].flag, node[j].h, node[j].m);
        
        for(int j = 0; j < t; j ++ )
        {
            if(!check(node[j].num))  continue;

            if(s.count(node[j].num))
            {
                if(now < maxn && (si[node[j].num] == 0 || i >= si[node[j].num] + m + 1))
                {
                    now ++ ;
                    si[node[j].num] = i;
                    printf("%s %s\n", node[j].name, node[j].num);
                }
            }
            else
            {
                if(now < maxn)  
                {
                    s.insert(node[j].num);
                    now ++ ;
                    si[node[j].num] = i;
                    printf("%s %s\n", node[j].name, node[j].num);
                }
            }

        }
        
    }
    
    // cout << idx << endl;
    for(int i = 0; i < idx; i ++ )
        printf("%s %s\n", res[i].name, res[i].num);
    
    
    return 0;
}