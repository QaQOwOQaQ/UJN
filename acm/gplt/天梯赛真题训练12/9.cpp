#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int n;
stack<int> a;
stack<char> b;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;  cin >> x;
        a.push(x);
    }
    for(int i = 1; i <= n - 1; i ++ )
    {
        char ch;    cin >> ch;
        b.push(ch);
    }
    
    while(b.size())
    {
        auto n1 = a.top();  a.pop();
        auto n2 = a.top();  a.pop();
        auto op = b.top();  b.pop();
        
        if(n1 == 0 && op == '/')    
        {
            printf("ERROR: %d/0\n", n2);
            return 0;
        }
        
        if(op == '+')   a.push(n2 + n1);
        else if(op == '-')  a.push(n2 - n1);
        else if(op == '*')  a.push(n2 * n1);
        else    a.push(n2 / n1);
    }
    
    cout << a.top() << endl;
}