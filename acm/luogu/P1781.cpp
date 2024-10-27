#include <iostream>
#include <cstring>

using namespace std;

// return a > b
bool cmp(string a, string b)    
{
    if(a.size() != b.size())    return a.size() > b.size();
    int len = a.size();
    for(int i = 0; i < len; i ++ )
        if(a[i] != b[i])
            return a[i] > b[i];
    return false;
}

int main()
{
    int n;  cin >> n;
    int id = -1;
    string cnt = "0";
    for(int i = 1; i <= n; i ++ )
    {
        string cur; cin >> cur;
        if(cmp(cur, cnt))
        {
            cnt = cur;
            id = i;
        }
    }
    cout << id << endl << cnt << endl;
    return 0;
}