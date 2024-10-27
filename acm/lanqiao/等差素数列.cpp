#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 100000;

int primes[N], idx;
bool st[N];

void get_primes()
{
    for(int i = 2; i <= M; i ++ )
    {
        if(!st[i])   primes[idx ++ ] = i;
        for(int j = 0; primes[j] <= M / i; j ++ )
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)  break;
        }
    }
    
}

bool check(int i, int d)
{
    int last = primes[i];
    for(int j = i + 1; j <= i + 10; j ++ )
    {
        if(primes[j] - last != d)   return false;
        last = primes[j];
    }
    return true;
}

int main()
{
    get_primes();
    
    // for(int i = 0; i < idx; i ++ )
    //     cout << primes[i] << " ";
    // cout << endl;
    
    /*
    for(int d = 1; ; d ++ )//1e2
    {
        for(int i = 0; i < idx / 100; i ++ )//1e4
        {
            bool flag = true;
            int x = primes[i];
            for(int k = 1; k <= 9; k ++ )
            {
                if(st[x + k * d])  
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cout << "公差:" << d << "\n首相:" << primes[i] << endl;
                return 0;
            }
        }
    }
    */
    cout << 210 << endl;
    return 0;
}