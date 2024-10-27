#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[20] = {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
int dy[20] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
int main()
{
    int n;  cin >> n;
    string s = "", t = "";
    for(int i = 1; i <= n; i ++ )   
        s += "*", t += " ";
    // cout << t << s << endl;
    for(int j = 0; j < 6 * n; j ++ )
    {
        for(int i = 1; i <= 11; i ++ )
        {
            if(dx[i])  cout << s;
            else    cout << t;
        }
        cout << endl;
    }
    for(int j = 0; j < n; j ++ )
    {
        for(int i = 1; i <= 11; i ++ )
        {
            if(dy[i])   cout << s;
            else    cout << t;
        }
        cout << endl;
    }
    return 0;
}