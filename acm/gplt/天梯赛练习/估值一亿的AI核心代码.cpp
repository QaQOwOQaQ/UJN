#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool check(char ch)
{
    if(ch >= '0' && ch <= '9')  return true;
    if(ch >= 'a' && ch <= 'z')  return true;
    if(ch >= 'A' && ch <= 'Z')  return true;
    return false;
}

void work(string s)
{
    int i;
    cout << s << endl << "AI: ";
    
    //tail' ''
    i = s.length() - 1;
    while(s[i] == ' ')  i -- ;
    s = s.substr(0, i + 1);
    
    //head' '
    i = 0;
    while(s[i] == ' ')  i ++ ;
    s = s.substr(i);
    
    //big->small
    for(int i = 0; i < s.length(); i ++ )
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(s[i] != 'I') s[i] += 32;
        }
    }
    
    //?-!
    for(int i = 0; i < s.length(); i ++ )
        if(s[i] == '?') s[i] = '!';
    
    // mid' '
    string b = s, c = "";
    for(int i = 0; i < b.length(); i ++ )
    {
        if(i != b.length() - 1 && b[i] == ' ' && !check(b[i + 1]))  continue;
        else    c += b[i];
    }
      
    // cout << "c: " << c << endl;
        
    //end operate
    s = c;
    for(int i = 0; i < s.length(); i ++ )
    {
        if(i && s[i - 1] == ' ' && s[i] == ' ') continue;
        else if(s.substr(i, 7) == "can you")
        {
            if((i - 1 == 0|| !check(s[i - 1])) && (i + 7 == s.length() - 1 || !check(s[i + 7])))
            {
                cout << "I can";
                i += 6;
            }
            else    cout << "c";
        }
        else if(s.substr(i, 9) == "could you")
        {
            if((i - 1 == 0|| !check(s[i - 1])) && (i + 9 == s.length() - 1 || !check(s[i + 9])))
            {
                cout << "I could";
                i += 8;
            }
            else    cout << "c";
        }
        else if(s[i] == 'I') 
        {
            if((i - 1 == 0 || !check(s[i - 1])) && (i + 1 == s.length() - 1 || !check(s[i + 1])))
                cout << "you";
            else    cout << "I";
        }
        else if(s.substr(i, 2) == "me")    
        {
            if((i - 1 == 0|| !check(s[i - 1])) && (i + 2 == s.length() - 1 || !check(s[i + 2])))
            {
                cout << "you";
                i += 1;
            }
            else    cout << "m";
        }
        else    cout << s[i];
    }
    cout << endl;
    
}

int main()
{
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i ++ )  
    {
        string s;
        getline(cin, s);
        work(s);
    }

    return 0;
}