#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
//26
int main()
{
    vector<int> v;
    int l, n;
    long long cnt = 1;
    
    cin >> l >> n;
    
    for(int i = 1; i <= l; i ++ )   cnt *= 26;
    cnt -= n;
    
    while(cnt)
    {
          v.push_back(cnt % 26);
          cnt /= 26;
    }
    
    while(v.size() < l) v.push_back(0);
    reverse(v.begin(), v.end());

    for(auto x : v)
    {
        char ch = 'a' + x;
        cout << ch;
    }
    return 0;
}