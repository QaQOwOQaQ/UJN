#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

const LL N = 59084709587505;
const LL M = 35;

set<LL> s;

void dfs(LL u)
{
    if(u > 40)   return ;
    if(u != 1)  s.insert(u);
    dfs(u * 3);
    dfs(u * 5);
    dfs(u * 7);
}

int main()
{
    dfs(1);
    cout << s.size() << endl;
    for(auto &x : s)
        cout << x << " ";
    cout << endl;
    cout << "test: ";
    //auto t = *s.end();
    cout << *s.lower_bound(15);
    return 0;
}