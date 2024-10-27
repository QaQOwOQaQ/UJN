#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

stack<int> res;

int main()
{
    int x;  
    while(cin >> x, x) res.push(x);
    while(res.size())
    {
        cout << res.top() << ' ';
        res.pop();
    }
    cout << endl;
    return 0;
}