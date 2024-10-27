#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string t = "chi1 huo3 guo1";
    int cnt = 0, idx = 0;
    int is_first = 0;
    while(1)
    {
        string s;
        getline(cin, s);
        if(s == ".")    break;
        idx ++ ;
        // cout << "s: " << s << endl; 
        if(s.find(t) != -1)
        {
            cnt++ ;
            if(!is_first)   is_first = idx;
        }
    }
    
    cout << idx << endl;
    if(!cnt)    puts("-_-#");
    else
    {
        cout << is_first << ' ' << cnt << endl;
    }
    
    return 0;
}