// 傻逼题卡格式

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, l;
int w[6] = {0, 30, 50, 60, 80, 100};

struct Node{
    string num;
    int grade;
    int level, w;
    int rank, all;
}node[N];

int getlevel(int x)
{
    if(x == 0)  return 0;
    if(x <= 30) return 1;
    if(x <= 50) return 2;
    if(x <= 60) return 3;
    if(x <= 80) return 4;
    return 5;
}

bool cmp(const Node &x, const Node &y)
{
    if(x.grade == y.grade)  return x.num < y.num; 
    return x.grade > y.grade;
}

int main()
{
    cin >> n >> l;
    for(int i = 0; i < n; i ++ )    
    {
        cin >> node[i].num >> node[i].grade;
        node[i].level = getlevel(node[i].grade);
        node[i].w = w[node[i].level];
        node[i].all = node[i].rank = 1;
    }
    
    for(int i = 0; i < n; i ++ )
    {
        for(int j = 0; j < n; j ++ )
        {
            if(i == j)  continue;
            if(node[j].level <= node[i].level)  node[i].all ++ , node[i].rank ++ ;
            if(node[j].level <= node[i].level && node[j].grade <= node[i].grade)  node[i].rank -- ;
        }
    }
    
    sort(node, node + n, cmp);
    
    for(int i = 0; i < n; i ++ )
    {
        cout << node[i].num;
        if(node[i].grade == 0) 
        {
            cout << endl;
            continue;
        }
        cout << ' ' << node[i].level;
        cout << ' ' << node[i].grade << '/' << node[i].w;
        cout << ' ' << node[i].rank << '/' << node[i].all;
        cout << endl;
    }
    
    
    return 0;
}