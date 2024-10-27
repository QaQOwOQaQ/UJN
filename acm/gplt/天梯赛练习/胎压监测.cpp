#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int w[4], minx, fa, maxn = -1;

    for(int i = 0; i < 4; i ++ )    cin >> w[i], maxn = max(maxn, w[i]);    
    cin >> minx >> fa;

    set<int> S;
    for(int i = 0; i < 4; i ++ )
    {
        if(w[i] < minx) S.insert(i + 1);
        if(maxn - w[i] > fa)    S.insert(i + 1);
    }
    if(S.size() == 1)   for(auto &x : S)    printf("Warning: please check #%d!", x);
    else if(S.size() == 0)   puts("Normal");
    else puts("Warning: please check all the tires!");
    return 0;
}