#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int w[10][10];
bool st[10];
int tomoney[] = {0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600, 0};

int main()
{
    for(int i = 1; i <= 3; i ++ )
        for(int j = 1; j <= 3; j ++ )
            cin >> w[i][j], st[w[i][j]] = true;
    
    int root = 0;
    for(int i = 1; i <= 9; i ++ )
        if(!st[i])
            root = i;
    
    for(int i = 1; i <= 3; i ++ )
        for(int j = 1; j <= 3; j ++ )
            if(!w[i][j])
                w[i][j] = root;
     
    for(int i = 1; i <= 3; i ++ )
    {
        int a, b;
        cin >> a >> b;
        cout << w[a][b] << endl;
    }
    
    int cnt = 0;
    int q;  cin >> q;
    if(q <= 3)
    {
        for(int i = 1; i <= 3; i ++ )
            cnt += w[q][i];
    }
    else if(q <= 6)
    {
        for(int i = 1; i <= 3; i ++ )
            cnt += w[i][q - 3];
    }
    else if(q == 7)
    {
        cnt = w[1][1] + w[2][2] + w[3][3];
    }
    else    
        cnt = w[1][3] + w[2][2] + w[3][1];
    
    
    // cout << "cnt: " << cnt << endl;
    
    cout << tomoney[cnt] << endl;
    
    return 0;
}