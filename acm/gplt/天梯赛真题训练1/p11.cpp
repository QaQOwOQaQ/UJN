#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int pre[N];
int tao[N], area[N], num[N];
bool st[N];
struct node{
    int id, num, tao, area;    
}p[N];

bool cmp(const node &x, const node &y)
{
    if(x.area * y.num == y.area * x.num)    return x.id < y.id;
    else    return x.area * y.num > y.area * x.num;
}

void init()
{
    for(int i = 0; i < N; i ++ )
    {
        pre[i] = i;
        num[i] = 1;
    }
}

int find(int x)
{
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}

void join(int x, int y)
{
    st[x] = st[y] = true;
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return ;
    if(fx < fy)
    {
        pre[fy] = fx;
        num[fx] += num[fy];
        area[fx] += area[fy];
        tao[fx] += tao[fy];
    }
    else
    {
        pre[fx] = fy;
        num[fy] += num[fx];
        area[fy] += area[fx];
        tao[fy] += tao[fx];
    }
}

int main()
{
    init();
    cin >> n;
    while (n -- )
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;    //编号，父母，孩子数
        st[a] = true;
        if(b != -1) join(a, b);
        if(c != -1) join(a, c);
        
        for(int i = 0; i < k; i ++ )    //孩子
        {
            int t;
            cin >> t;
            join(a, t);
        }
        int x, y;
        cin >> x >> y;  //房产套数 总面积
        tao[find(a)] += x;  //tao[a] += x;错误！！！
        area[find(a)] += y; 
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i ++ )
    {
        if(st[i] && pre[i] == i)
        {
            p[cnt].id = i;
            p[cnt].num = num[i];
            p[cnt].area = area[i];
            p[cnt].tao = tao[i];
            cnt ++ ;
        }
    }
    
    sort(p, p + cnt, cmp);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i ++ )
        printf("%04d %d %.3f %.3f\n", p[i].id, p[i].num, p[i].tao * 1.0 / p[i].num, p[i].area *1.0 / p[i].num);;
    
    
    return 0;
}