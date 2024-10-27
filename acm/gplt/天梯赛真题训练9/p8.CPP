#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, len;
    string add, goal;
    cin >> n >> add;
    getchar();
    getline(cin, goal);
    // cout << goal << endl;
    len = goal.length();
    if(n <= len)
    {
        cout << goal.substr(len - n);
    }
    else
    {
        for(int i = 0; i < n - len; i ++ )
            cout << add;
        cout << goal << endl;
    }
    
    
    return 0;
}