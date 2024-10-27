#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

string last = "012345678", goal = "087654321";
struct node{
    string str;     //state
    int pos;    //pos[0]
    int cnt;    
    node(string s, int a, int b) : str(s), pos(a), cnt(b) {}  
};
queue<node> q;
set<string> S;

void query_add(node t, int x)   //x表示交换的位置
{
    x = (t.pos + x + 9) % 9;    //得到交换的位置
    string s = t.str;
    swap(s[x], s[t.pos]);
    node newNode(s, x, t.cnt + 1);
    q.push(newNode);
}

int main()
{
    node start(last, 0, 0);
    q.push(start);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        if(!S.count(t.str))
        {
            if(t.str == goal)
            {
                cout << "res: " << t.cnt << endl; 
                return 0;
            }
            else
            {
                S.insert(t.str);
                //bfs
                query_add(t, -1);
                query_add(t, 1);
                query_add(t, -2);
                query_add(t, 2);
            }
        }
    }
    
    return 0;
}