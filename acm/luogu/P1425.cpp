#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int h1, m1, h2, m2;
    cin >> h2 >> m2 >> h1 >> m1;
    int sum = h1 * 60 + m1 - h2 * 60 - m2;
    cout << sum / 60 << ' ' << sum % 60 << endl;
    return 0;
}