#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;  cin >> n;
    while(n -- )
    {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if(a < 15 || a > 20 || b < 50 || b > 70)
            cout << s << endl;
    }
    
    return 0;
}