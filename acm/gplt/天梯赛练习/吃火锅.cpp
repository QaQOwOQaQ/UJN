#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int sum = 1;
    int cnt = 0;
    int first = 0;
    bool flag = false;
    while(getline(cin, s))
    {
        if(s == ".")    break;
        else    
        {
            if(s.find("chi1 huo3 guo1") != -1)
            {
                if(!flag)  
                {
                    first = sum;
                    flag = true;
                }
                cnt ++ ;
            }
        }
        sum ++ ;
    }
    cout << sum - 1 << endl;
    if(!cnt)    cout << "-_-#" << endl;
    else    cout << first << " " << cnt << endl;
    return 0;
}