#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string a="", b="";
    string s;
    int cnt = 1;
    while(cin >> s)
    {
        if(s == ".")    break;
        if(cnt == 2)    a = s;
        if(cnt == 14)   b = s;
        cnt ++ ;
    }
    
    if(a=="")   printf("Momo... No one is for you ...");
    else if(b=="") printf("%s is the only one for you...", a.c_str());
    else    printf("%s and %s are inviting you to dinner...", a.c_str() , b.c_str());
    return 0;
}