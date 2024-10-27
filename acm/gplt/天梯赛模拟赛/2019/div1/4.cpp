#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 正常人睡眠时的呼吸频率是每分钟15-20次
// 脉搏是每分钟50-70次
// 请你找出他们中间有可能在装睡的人
// 即至少一项指标不在正常范围内的人。

int main()
{
    int n;  cin >> n;
    while (n -- )
    {
        string name;
        int a, b;
        cin >> name >> a >> b;
        if(b < 50 || b > 70 || a < 15 || a > 20)
            cout << name << endl;
    }
    
    return 0;
}