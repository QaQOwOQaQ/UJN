#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, d, k, idx;
PII w[N];
vector<int> v[N];
set<int> s, res;
map<int, int> md;//idx->id
map<int, int> mx;//id->idx

int main()
{
    cin >> n >> d >> k;
    for(int i = 0; i < n; i ++ )
        cin >> w[i].y >> w[i].x;
        
    sort(w, w + n);
    /*
    for (int i = 0; i < n; i ++ )
        cout << w[i].x << " " << w[i].y << endl;
    */
    for(int i = 0; i < n; i ++)
    {
        int id = w[i].x;
        if(!s.count(id))
        {
            s.insert(id);
            md[idx] = id;
            mx[id] = idx;
            v[idx].push_back(w[i].y);
            idx ++ ;
        }
        else v[mx[id]].push_back(w[i].y);
    }   
    
    for(int i = 0; i < idx; i ++ )
    {
        int len = v[i].size();
        if(len < k)    continue;
        else if(len == k && v[i][len - 1] - v[i][0] < d)   res.insert(md[i]);
        else//v[i].size()>k
        {
            for(int j = 0; j < len; j ++ )
            {
                int ne = j + k - 1;
                if(ne < len && v[i][ne] - v[i][j] < d)
                {
                    res.insert(md[i]);
                    break;
                }
            }
        }
    }
    
    // cout << "size: " << res.size() << endl;
    for(auto &x : res)  
        cout << x << endl;

}
