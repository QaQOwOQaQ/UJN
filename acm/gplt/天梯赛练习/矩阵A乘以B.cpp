#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n1, n2, m1, m2;
int a[N][N], b[N][N], c[N][N];

int main()
{
    cin >> n1 >> m1;
    for(int i = 0; i < n1; i ++ )
        for(int j = 0; j < m1; j ++ )
            cin >> a[i][j];
    
    cin >> n2 >> m2;
    for(int i = 0; i < n2; i ++ )
        for(int j = 0; j < m2; j ++ )
            cin >> b[i][j];
    
    if(m1 != n2)    printf("Error: %d != %d", m1, n2);
    else
    {
        for(int i = 0; i < n1; i ++ )
        {
            for(int j = 0; j < m2; j ++ )
            {
                for(int k = 0; k < m1; k ++ )
                    c[i][j] += a[i][k] * b[k][j];
            }
        }
        cout << n1 << " " << m2 << endl;
        for(int i = 0; i < n1; i ++ )
        {
            for(int j = 0; j < m2; j ++ )
            {
                cout << c[i][j];
                if(j != m2 - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
    
}