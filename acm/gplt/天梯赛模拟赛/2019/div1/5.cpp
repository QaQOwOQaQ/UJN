#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    string res = to_string(a * b);
    reverse(res.begin(), res.end());
    int idx = 0;
    while(res[idx] == '0')  idx ++ ;
    for(int i = idx; i < res.size(); i ++ ) cout << res[i];
    cout << endl;
    return 0;
}