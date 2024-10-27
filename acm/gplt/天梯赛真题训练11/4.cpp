#include <iostream>

using namespace std;

int num, n;
/*
纸牌会变成等量的硬币，而硬币变成纸牌时，纸牌的数量会加倍
*/
int main()
{
    cin >> num >> n;
    for(int i = 1; i <= n; i ++ )
    {
        if(i % 2 == 0)   num *= 2;
    }
    if(n & 1)   cout << 1 << " ";
    else    cout << 0 << " ";
    cout << num << endl;
    return 0;
}