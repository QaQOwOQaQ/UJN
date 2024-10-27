#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<string> s;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        string str;   cin >> str;
        if(!s.count(str))  printf("Hello %s, how are you?\n", str.c_str());
        else    printf("Hi %s! Glad to see you again!\n", str.c_str());
        s.insert(str); 
    }
    
    return 0;
}