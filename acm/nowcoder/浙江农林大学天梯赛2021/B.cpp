/*
通过模拟可以看出来本题和奇偶行有关
那么猜就行了，就n和m两个变量，n+m，n*m......
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, m;

int main()
{
    cin >> T;
    while(T -- )
    {
        int cnt = 0;
        cin >> n >> m;
        if((n * m % 2) == 0)    puts("SHT");
        else    puts("GensokyoLOvEr");
    }

    return 0;
}