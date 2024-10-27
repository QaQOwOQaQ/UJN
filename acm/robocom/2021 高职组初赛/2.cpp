#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    int x, y, z;
    cin >> x >> y >> z;
    int ax = a - x, by = b - y, cz = c - z;
    int sum = abs(ax) + abs(by) + abs(cz);
    printf("Diff = %d, %d, %d\n", ax, by, cz);
    if(sum <= t)    puts("Yes");
    else    puts("No");
    return 0;
}