#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<double, double> PDD;

int main()
{
    set<PDD> S;
    set<int> y;
    set<int> x;
    int x1, y1, x2, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    bool flag = false;
    for(int i = x1; i <= x2; i ++ )//x1
        for(int j = y1; j <= y2; j ++ )//y1
            for(int m = x1; m <= x2; m ++ )//x2
                for(int n = y1; n <= y2; n ++ )//y2
                {
                    if(i == m)  x.insert(i);
                    else if(n == j) y.insert(j);
                    else
                    {
                        double k = 1.0*(n-j)/(m-i);    //xie lv
                        double d = 1.0*(m*j-i*n)/(m-i);
                        S.insert({k, d});
                    }
                }
                
                
    // for(auto &x : S)
    //     cout << x.first << " " << x.second << endl;
    
    cout << S.size() + x.size() + y.size();
    return 0;
}