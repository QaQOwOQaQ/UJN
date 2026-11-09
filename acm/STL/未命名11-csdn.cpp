#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n,cnt;
stack<string>a,b;

int main()
{
    cin >> n;
    while(n--)
    {
        string tmp;
        a.push("http://www.lightoj.com/");
        cout << "Case " << ++cnt << ":" <<endl;
        while(cin >> tmp)
        {
            if(tmp[0] == 'V') //VISIT
            {
                string web;
                cin >> web;
                a.push(web);
                while(!b.empty()) b.pop();
                cout << web << endl;
            }
            else if(tmp[0] == 'B') //BACK
            {
                if(a.size() > 1)
                {
                    b.push(a.top());
                    a.pop();
                    cout << a.top() << endl;
                }
                else
                {
                    cout << "Ignored" << endl;
                }
            }
            else if(tmp[0] == 'F') //FORWARD
            {
                if(b.empty())
                {
                    cout << "Ignored" << endl;
                }
                else
                {
                    a.push(b.top());
                    b.pop();
                    cout << a.top() << endl;
                }
            }
            else if(tmp[0] == 'Q') //QUIT
            {
                while(!a.empty()) a.pop();
                while(!b.empty()) b.pop();
                break;
            }
        }

    }

    return 0;
}

