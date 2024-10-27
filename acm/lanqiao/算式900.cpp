#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
bool st[100];

bool check()
{
    if(v.size() >= 1 && !v[0])  return false;
    if(v.size() >= 5 && !v[4])  return false;
    if(v.size() >= 9 && !v[8])  return false;
    return true;
}

bool checkres()
{
    int a = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    int b = v[4] * 1000 + v[5] * 100 + v[6] * 10 + v[7];
    int c = v[8] * 10 + v[9];
    if((a - b) * c == 900)  return true;
    return false;
    
}

void dfs(int u)
{
    if(u > 10)
    {
        if(!checkres())  return ;
        for(int i = 0; i < 10; i ++ )
            cout << v[i] << " ";
        cout << endl;
        return ;
    }
    if(!check()) return ;
    
    for(int i = 0; i <= 9; i ++ )
    {
        if(!st[i])
        {
            st[i] = true;
            v.push_back(i);
            dfs(u + 1);
            st[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    //dfs(1);
    string s = "(6048-5973)*12=900";
    cout << s << endl;
    return 0;
}