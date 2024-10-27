#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string a;
    int d, t = 0;
    cin >> a >> d;
    if(a == "0") // 特判
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> res;
    if(d == 10)
    {
        for(auto &x : a) t = t * 10 + x - '0';
        while(t)
        {
            res.push_back(t % 27);
            t /= 27;
        }
        reverse(res.begin(), res.end());
        for(auto &x : res)
        {
            if(x >= 0 && x <= 9)    cout << x;
            else  
            {
                char ch = 'A' + (x - 10);
                cout << ch;
            }
        }
        cout << endl;
    }
    else //27
    {
        int in = 0;
        for(auto &x : a)
        {
            if(x >= '0' && x <= '9')    in = x - '0';
            else    in = x - 'A' + 10;
            t = t * 27 + in;
        }
        cout << t << endl;
    }
    
    return 0;
}
