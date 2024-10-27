#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, tree[100];

void create(int u)
{
    if(u > n)   return ;
    create(u * 2);
    create(u * 2 + 1);
    cin >> tree[u];
}


int main()
{
    cin >> n;
    create(1);
    
    for(int i = 1; i <= n; i ++ )
    {
        cout << tree[i];
        if(i != n)  cout << " ";
    }
    cout << endl;
    
    return 0;
}