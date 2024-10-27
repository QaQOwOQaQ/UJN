#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int x = 2019;

    while(x)
    {
        v.push_back(x % 26);
        x /= 26;
    }
    for (int i = v.size() - 1; i >= 0; i -- )
    {
        char ch = v[i] + 64;
        cout << ch;
    }
    return 0;
}