#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 1200000;

set<int> S;

void get()
{
    for(int i = 1; i <= N / i; i ++ )
    {
        if(N % i == 0)
        {
            S.insert(i);
            S.insert(N / i);
        }
    }
}

int main()
{
    get();
    cout << S.size();
    return 0;
}