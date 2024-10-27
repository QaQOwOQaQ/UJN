#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    string s;   cin >> s;
    stack<int> num;
    stack<char> op;
    int len = s.size();
    for(int i = 0; i < len; i ++ )
    {
        if(s[i] == '.' || s[i] == '@') continue;
        else if(s[i] >= '0' && s[i] <= '9')
        {
            int j = i, cur = 0;
            while(s[j] >= '0' && s[j] <= '9')
            {
                cur = cur * 10 + s[j] - '0';
                j ++ ;
            }
            i = j - 1;
            num.push(cur);
        }
        else 
        {
            int c;
            auto b = num.top(); num.pop();
            auto a = num.top(); num.pop();
            switch(s[i])
            {
                case '+': c = a + b;     break;
                case '-': c = a - b;     break;
                case '*': c = a * b;     break;
                case '/': c = a / b;     break;
            }
            num.push(c);
        }
    }
    cout << num.top() << endl;
    return 0;
}