#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
string s[100];

int main()
{
    cin >> n >> m;
    getchar();
    for(int i = 0; i < n; i ++ )    getline(cin, s[i]);
    
    int i;
    for (i = 0; i < n; i ++ )   
    {
        if(s[i].find("easy") != -1 || s[i].find("qiandao") != -1)   continue;
        else 
        {
            if(m)   m -- ;
            else    break;
        }
    }

    if(i >= n)   cout << "Wo AK le";
    else    cout << s[i];
}