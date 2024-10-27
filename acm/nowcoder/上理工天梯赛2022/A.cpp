/*
multiset的简单应用
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100010;

int n;
int a[N], b[N];
multiset<int, greater<int> > s;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    
    {
        cin >> a[i];
        s.insert(a[i]);
    }    
    for(int i = 0; i < n; i ++ )
    {
        bool is_first = true;
        for(auto &x : s)
        {
            if(x == a[i] && is_first)   is_first = false;
            else   
            {
                cout << x + a[i] << " ";
                break;
            }
        }
    }
    
    
    
    
    return 0;
}