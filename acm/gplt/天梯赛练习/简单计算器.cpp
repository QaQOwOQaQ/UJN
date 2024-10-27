#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 1010;

int n;
stack<int> a;
stack<char> s;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x;  cin >> x;
        a.push(x);
    }
    for(int i = 0; i < n - 1; i ++ )
    {
        char ch;    cin >> ch;
        s.push(ch);
    }
    
    while(!s.empty())
    {
        int n1 = a.top();   a.pop();
        int n2 = a.top();   a.pop();
        char op = s.top();  s.pop();
        if(n1 == 0 && op == '/')
        {
            printf("ERROR: %d/0\n", n2);
            return 0;
        }
        if(op == '+')   a.push(n1 + n2);
        else if(op == '-')  a.push(n2 - n1);
        else if(op == '*')  a.push(n2 * n1);
        else a.push(n2 / n1);
    }
    
    cout << a.top() << endl;
    
    return 0;
}