#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int w[100];

int main()
{
    int x;
    for(int i = 0; i < 24; i ++ )   cin >> w[i];
    while(cin >> x)
    {
        if(x < 0 || x > 23) break;
        else    cout << w[x] << " ";
        if(w[x] > 50)   cout << "Yes" << endl;
        else    cout << "No" << endl;
    }
    
    
    return 0;
}