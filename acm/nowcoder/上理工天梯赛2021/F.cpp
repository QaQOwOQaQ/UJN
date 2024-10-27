/*
细节决定成败：交换字符串ss中任意相邻位置的两个字符
注意相邻位置！！！

其次，本题的核心在于观察出比较串AKGPLT是以A开头的
那么也就是说，只要字符串存在一个大于A的字符，那么就肯定有解！
无解的情况：AAAA......
然后就是找到这个交换次数，因为除了A之外的所有字符都大于A
所以我们可以与A做交换，这样大于关系肯定成立
但要注意的是，如果当前字符大于K，那么我们可以与K做交换

分情况讨论一下吧
如果给定字符串s等于匹配串t，res=0
否则，s的第一个字符肯定为A
这时候第二个字符有两种情况（如果第二个字符存在的话）
（1）不等于A，也就是大于A，直接与第一个A交换，res=1
（2）等于A，继续往后寻找，直到找个一个大于A的
    这时候截止到我们找到的字符串是：A...A@（我们用@表示一个大于A的字符）
    为了保证字符串的大于关系，我们找到的字符@肯定要与前面的某个字符A交换
    交换哪一个呢？
    由于A小于所有字符（除了自己），所以我们只能往前交换交换第一个或者第二个字符！
    显然往后交换是肯定不行的，交换其余的也是不行的
    并且只有当@>K的时候才可以交换第二个字符
    至此，就与上面的分析不谋而合了
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
string s, t = "AKGPLT";

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int res = 0;
        cin >> s;
        if(s > t)  res = 0;
        else
        {
            int len = s.length();
            for(int j = 0; j < len; j ++ )
            {
                if(s[j] > 'A')
                {
                    if(s[j] > 'K')    res = j - 1;
                    else res = j;
                    break;
                }
            }
            if(res == 0)    res = -1;
        }
        cout << res << endl;
    }
    
    return 0;
}
