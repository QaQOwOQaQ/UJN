#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<string, double> PSI;

const int N = 100010;

int n, m;
set<string> S;
vector<string> res;
PSI w[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        string s;
        cin >> s;
        S.insert(s);
    }
    cin >> m;
    
    int sum = 0;
    for(int i = 0; i < m; i ++ )
    {
        cin >> w[i].x >> w[i].y;
        sum += w[i].y;
    }
    double ave = 1.0 * sum / m;
    
    int cnt = 0;
    for(int i = 0; i < m; i ++ )
    {
        if(w[i].y > ave && !S.count(w[i].x))    
        {
            res.push_back(w[i].x);
            cnt ++ ;
        }
    }
    
    if(!cnt)    cout << "Bing Mei You" << endl;
    else
    {
        sort(res.begin(), res.end());
        for(auto &s : res)  cout << s << endl;
    }   
    return 0;
}