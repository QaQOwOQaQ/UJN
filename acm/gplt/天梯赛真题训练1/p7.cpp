#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int col, row;
char ch;

int main()
{
    cin >> col >> ch;
    row = (double)col / 2 + 0.5;
    // cout << "row: " << row << endl;
    
    for(int i = 1; i <= row; i ++ )
    {
        for(int j = 1; j <= col; j ++ )
            cout << ch;
        cout << endl;
    }
    
    return 0;
}