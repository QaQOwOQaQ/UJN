#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    char ch;
    string s;
    cin >> n >> ch;
    // 注意s可能包含空格
    getchar();
    getline(cin, s);
    m = s.size();
    if(m > n)
    {
        cout << s.substr(m - n, n) << endl;
    }
    else
    {
        while(m < n)
        {
            s = ch + s;
            m ++ ;
        }
        cout << s << endl;
    }
    return 0;
}