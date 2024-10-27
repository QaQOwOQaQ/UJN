//score3
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000010;

int n, q, tr[N];
int st[N];

int getLevel(int x)
{
    int cnt = 0;
    while(x)
    {
        x /= 2;
        cnt ++ ;
    }
    return cnt;
}

void insert(int x)
{
    int pos = 1;
    while(1)
    {
        if(tr[pos] == -1)
        {
            tr[pos] = x;
            st[x] = pos;
            return ;
        }
        else if(x < tr[pos])    pos *= 2;
        else    pos = pos * 2 + 1;
    }
}

int main()
{
    memset(tr, -1, sizeof tr);
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x;  cin >> x;
        insert(x);
    }
    
    
    cin >> q;
    while(q -- )
    {
        int a, b;
        string s1, s2, s3, s4, s5, s6;
        cin >> a >> s1;
        
        bool flag = true;
        if(s1 == "is")
        {
            cin >> s2 >> s3;
            if(s3 == "root")//A is the root
            {
                if(st[a] != 1)  flag = false;
            }
            else if(s3 == "parent")//A is the parent of B
            {
                cin >> s4 >> b;
                if((st[b] / 2) != st[a])  flag = false;
            }
            else if(s3 == "left")//A is the left child of B
            {
                cin >> s4 >> s5 >> b;
                if((st[a] * 2) != st[b]) flag = false;
            }
            else//A is the right child of B
            {
                cin >> s4 >> s5 >> b;
                if((st[a] * 2 + 1) != st[b]) flag = false;
            }
        }
        else    //and
        {
            cin >> b >> s2 >> s3;
            if(s3 == "on")//A and B are on the same level
            {
                cin >> s4 >> s5 >> s6;
                if(getLevel(st[a]) != getLevel(st[b]))  flag = false;
            }
            else//A and B are siblings
            {
                if(st[a] / 2 != st[b] / 2)  flag = false;
            }
        }
        if(flag)    puts("Yes");
        else    puts("No");
    }
    
    
    return 0;
}