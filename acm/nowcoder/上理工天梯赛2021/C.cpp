//规律：数字的和
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

const int N = 1010;

int n;
string s;
LL num[N];
int cnt1, cnt2;
map<LL, LL> m;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        LL res = 0;
        cin >> s;
        for(int j = 0; j < s.length(); j ++ )
            res += s[j] - '0';
        num[i] = res;
        m[res] ++ ;
    }
    
    for(int i = 0; i < n; i ++ )
    {
        if(m[num[i]] == 1){
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}