#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N];

int init()
{
    a[1] = 1;
    for(int i = 2; ; i ++ )
    {
        a[i] = a[i - 1] + (2 * i - 1) * 2; 
        if(a[i] > 1000) break;
    }
}

int main()
{
    init();
    
    int n, rows;
    char c;
    cin >> n >> c;
    for(int i = 1; ; i ++ )
    {
        if(n < a[i])    break;
        else    rows = i;
    }
    // cout << rows << endl;
    for(int i = rows; i >= 1; i -- )
    {
        for(int j = 1; j <= 2 * rows - 1 - (rows - i); j ++ )
        {
            if(j >= rows - (i - 1) && j <= rows + (i - 1)) cout << c;
            else    cout << ' ';
        }
        cout << endl;
    }
    
    for(int i = 2; i <= rows; i ++ )
    {
        for(int j = 1; j <= 2 * rows - 1 - (rows - i); j ++ )
        {
            if(j >= rows - (i - 1) && j <= rows + (i - 1)) cout << c;
            else    cout << ' ';
        }
        cout << endl;
    }

    cout << n - a[rows];
    
    
    return 0;
}