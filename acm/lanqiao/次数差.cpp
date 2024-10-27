#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int w[30];

int main()
{
    string s;
    while(cin >> s)
    {
        memset(w, 0, sizeof w);
        for(auto &x : s)    w[x-'a'] ++ ;
        int l = 1010, r = -1;
        for(int i = 0; i < 26 ; i ++ )
        {
            if(w[i] && w[i] > r)    r = w[i];
            if(w[i] && w[i] < l)    l = w[i];
        }
        cout << r - l << endl;
    }

    
    return 0;
}