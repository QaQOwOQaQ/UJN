#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;  
    getline(cin, s);
    int n = s.length(), cnt = 0;
    for(int i = 0; i < n; i ++ )
    {
        if(s[i] != '6') 
        {
            if(cnt && cnt <= 3)
                for(int i = 0; i < cnt; i ++ )  cout << 6;
            else if(cnt && cnt <= 9)
                cout << 9;
            else if(cnt)
                cout << 27;
            cout << s[i];
            cnt = 0;
        }
        
        else    cnt ++ ;
    }
    //最后还要判断一下
            if(cnt && cnt <= 3)
                for(int i = 0; i < cnt; i ++ )  cout << 6;
            else if(cnt && cnt <= 9)
                cout << 9;
            else if(cnt)
                cout << 27;
    cout << endl;
    
    return 0;
}