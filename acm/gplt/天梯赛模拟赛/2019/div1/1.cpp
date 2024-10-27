#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 但题目保证所有K超过1的朋友圈里都至少有2个不同的人。

const int N = 110;

int n, idx;
unordered_set<int> has;
unordered_map<int,int> w;

int main()
{
    cin >> n;
    while (n -- )
    {
        int k;  cin >> k;
        unordered_set<int> st;
        for(int i = 0; i < k; i ++ )
        {
            int x;  cin >> x;
            st.insert(x);
        }
        if(st.size() > 1)
        {
            for(auto &x : st)   has.insert(x);
        }
    }
    int m;  cin >> m;
    unordered_set<int> res;
    while (m -- )
    {
        int k;  cin >> k;
        if(!w[k])   w[k] = ++ idx;
        if(!has.count(k))   res.insert(k);
    }
    if(res.size() == 0) puts("No one is handsome");
    else {
        vector<int> t(res.begin(), res.end());
        sort(t.begin(), t.end(), [&](int l, int r){
            return w[l] < w[r];
        });
        for(int i = 0; i < t.size(); i ++ )
            cout << t[i] << " \n"[i == t.size() - 1];
    }
    return 0;
}