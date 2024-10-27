/*
    就看你细不细心了！！！
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
bool has_answer;
bool st[10];

bool check()
{
    int a = 0, b = 0, c = 0;
    int maxn = 0, t = 0, last = v[0];
    int sum_zhi = 0;
    
    if(v[8] != 3 || v[9] != 3)  return false;//9,10
    for(int i = 0; i <= 9; i ++ )
    {
        int x = v[i];
        
        if(x == 1)  a ++ ;
        else if(x == 2) b ++ ;
        else c ++;
        
        if(x == last)   t ++ ;
        else
        {
            maxn = max(t, maxn);
            last = x;
            t = 1;
        }
    }
    maxn = max(maxn, t);
    
    if(a == 2 || a == 3 || a == 5 || a == 7)   sum_zhi ++ ;
    if(b == 2 || b == 3 || b == 5 || b == 7)   sum_zhi ++ ;
    if(c == 2 || c == 3 || c == 5 || c == 7)   sum_zhi ++ ;
    
    if(v[0] != sum_zhi) return false;//1
    
    if(v[1] + 1 != b)   return false;//2
    
    if(abs(c - a) != 4 - v[2])  return false;//3
    
    if(abs(v[3] - v[2]) != 3 - v[3])    return false;//4
    
    if(v[4] == 1 && v[1] != v[2])   return false;//5
    else if(v[4] == 2 && v[3] != v[4]) return false;
    else if(v[4] == 3 && v[5] != v[6])   return false;
    
    if(v[5] == 1 && a != 2) return false;//6
    else if(v[5] == 2 && b != 3) return false;
    else if(v[5] == 3 && c != 4) return false;
    if(v[6] + 1 != maxn)    return false;
    
    has_answer = true;
    return true;
}

void dfs(int u)
{
    if(u > 10)
    {
        if(check())
        {
            // cout << "res: " << endl;
            for(auto &x : v)
            {
                char ch = 'A' + x - 1;
                cout << ch;
            }
            cout << endl;
        }
        return ;
    }
    if(has_answer)  return ;
    for(int i = 1; i <= 3; i ++ )
    {
        v.push_back(i);
        dfs(u + 1);
        v.pop_back();
    }
    
}

int main()
{
    dfs(1);
    
    
    return 0;
}