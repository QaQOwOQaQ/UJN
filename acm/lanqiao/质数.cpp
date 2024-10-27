#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int primes[N], idx;
bool st[N];

void get_primes()
{
    for(int i = 2; i <= 21000; i ++ )
    {
        if(!st[i])   primes[idx ++ ] = i;
        for(int j = 0; primes[j] <= 21000 / i; j ++ )
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)  break;
        }
    }
}

int main()
{
    get_primes();

    
    cout << primes[2018] << endl;
    
    return 0;
}