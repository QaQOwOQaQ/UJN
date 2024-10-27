/*
说出来可能不信
模拟了几遍之后我看差不多就交了
结果一次模拟的时候是输出的20个，WRONG了
然后改为50还是WRONG，一看我输出了cpp(应该是mp4)
然后就AC了
挺莫名其妙的
幸福来得太突然
没想到这么简单
我还以为挺复杂的
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 50;

int n, cnt;

void out(int x)
{
    cout << x << ".mp4" << endl;
}

int main()
{
    cin >> n;
    int x = 1;
    while(x <= n)
    {
        out(x);
        cnt ++ ;
        x *= 10;
    }
    while(cnt < N)
    {
        x ++ ;
        if(x > n)
        {
            x -- ;
            x /= 10;
            x ++ ;
        }
        if(x % 10 == 0)
        {
            out(x / 10);
            cnt ++ ;
            if(cnt == 50)   break;
            out(x);
            cnt ++ ;
        }
        else
        {
            out(x);
            cnt ++ ;
        }
    }
    
    return 0;
}
