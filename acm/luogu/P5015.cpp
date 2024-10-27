#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    getchar();
    int len = s.size();
    for(auto &ch : s)   len -= ch == ' ';
    cout << len << endl;
    return 0;
}