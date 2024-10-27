#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int x;  cin >> x;
    if(x == 6)  cout << 1 << endl;
    else if(x == 7)  cout << 2 << endl;
    else cout << x + 2 << endl;
    return 0;
}