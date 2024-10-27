#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 100010;

LL n = 2021041820210418;
LL m = 100;
vector<LL> a;

int main()
{
    for(LL i = 1; i <= n / i; i ++ )
    {
        if(n % i == 0)  
        {
            a.push_back(i);
            if(i != n / i)  a.push_back(n / i);
        }
    }

    int res = 0;
    for (int i = 0; i < a.size(); i ++ )
        for (int j = 0; j < a.size(); j ++ )
        {
            if(n%(a[i]*a[j]) == 0)
                res++;
        }
    cout << res << endl;
    return 0;
}