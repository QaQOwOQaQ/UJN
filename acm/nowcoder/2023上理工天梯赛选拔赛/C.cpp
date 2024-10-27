// 卡cin,cout是真的没意思啊
// 不过好像因为输出输出没卡，AC之后不计罚时
// 好吧，勉强原谅你了。。。
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e6 + 10;

int n, T;
bool row[N], col[N], l[N], r[N];

int main()
{
    // 不然他就会放弃这次操作
    scanf("%d%d", &n, &T);
    while( T -- )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(row[x] || col[y] || l[x + y] || r[y - x + n]) 
        {
            printf("No\n");
        }
        else    
        {
            printf("Yes\n");
            row[x] = col[y] = l[x + y] = r[y - x + n] = true;
        }
    }
    
    return 0;
}