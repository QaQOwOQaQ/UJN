#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char c[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
    cin >> n;
    bool flag = true;
    for(int i = 0; i < n; i ++ )
    {
        string s;
        cin >> s;
        int t = 0;
        bool flag_t = true;
        for(int i = 0; i < 17; i ++ )
        {
            if(s[i] < '0' && s[i] > '9')
            {
                flag = false;
                flag_t = false;
                cout << s << endl;
                break;
            }
            else    t = (t + (s[i] - '0') * w[i]) % 11;
        }
        if(flag_t && c[t] != s[17])
        {
            flag = false;
            cout << s << endl;
        }
    }
    if(flag)    cout << "All passed" << endl;
    
    return 0;
}