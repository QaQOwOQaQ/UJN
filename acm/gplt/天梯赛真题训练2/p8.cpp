#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n <= 5)  cout << n + 2 << endl;
    else if(n == 6) cout << 1 << endl;
    else if(n == 7) cout << 2 << endl;
    
    return 0;
}