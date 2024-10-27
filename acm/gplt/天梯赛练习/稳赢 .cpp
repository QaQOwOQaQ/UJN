#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    cin >> k;
    string s;
    int cnt = 1;
    while(cin >> s)
    {
        if(s == "End")  break;

        if(cnt <= k)
        {
            if(s == "ChuiZi")   puts("Bu");
            else if(s == "JianDao")  puts("ChuiZi");
            else if(s == "Bu")   puts("JianDao");
            cnt ++ ;
        }
        else
        {
            cout << s << endl;
            cnt = 1;
        }
    }
    return 0;
}