#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> v;
int n, a, b;

int main()
{
    cin >> a >> b >> n;
    v.push_back(a);
    v.push_back(b);
    
    for(int i = 0; ; i ++ )
    {
        int t = v[i] * v[i + 1];
        if(t < 10)  v.push_back(t);
        else    v.push_back(t / 10), v.push_back(t % 10);
        if(v.size() > n)    break;
    }
    for(int i = 0; i < n; i ++ )
    {
        cout << v[i];
        if(i != n - 1)  cout << ' ';
    }

    return 0;
}