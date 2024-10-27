#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[1000][1000];

int main()
{
    int n, len, cols;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    len = s.length();
    cols = len % n == 0 ? len / n : (len / n + 1);
    
    int cnt = 0;
    for(int i = cols; i >= 1; i -- )    //lie
    {
        for(int j = 1; j <= n; j ++ )   //hang
        {
            if(cnt < len)   a[j][i] = s[cnt];
            else    a[j][i] = ' ';
            cnt ++ ;
        }
    }
    
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= cols; j ++ )
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}