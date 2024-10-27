#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct circle_t {
    int x, y, r;   
    // 按半径从小到大排序
    bool operator<(const circle_t &x) {
        return r < x.r;
    }
} Circle;

int n;
Circle c[53];

/*
按半径从小到大枚举圆，维护cnt，初始为0
1.如果(x1,y1)和(x2,y1)同时在这个圆，返回cnt
2.如果(x1,y1)和(x2,y1)同时不在这个圆，cnt不变
3.否则，如果其中一个点被这个圆包含，cnt++，因为从被包含的点出发到不被包含的点
    一定要走出这个被包含的圆
*/

bool check(int a, int b, int i)
{
    double dx = a - c[i].x;
    double dy = b - c[i].y;
    return sqrt(dx * dx + dy * dy) <= c[i].r;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> c[i].x;
    for(int i = 0; i < n; i ++ )    cin >> c[i].y;
    for(int i = 0; i < n; i ++ )    cin >> c[i].r;
    sort(c, c + n);
    
    int cnt = 0;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    for(int i = 0; i < n; i ++ )
    {
        // have=true,被包含
        bool have1 = check(x1, y1, i);
        bool have2 = check(x2, y2, i);
        if(have1 && have2)  break;
        else if(have1 || have2) cnt ++ ;
    }
    cout << cnt << endl;
    return 0;
}