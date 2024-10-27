#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int w[24], q;

int main()
{
    for(int i = 0; i <= 23; i ++ )  cin >> w[i];
    
    while(cin >> q)
    {
        if(q < 0 || q > 23) break;
        if(w[q] > 50)  cout << w[q] << " " << "Yes" << endl;
        else    cout << w[q] << " " << "No" << endl;
    }
    
    return 0;
}