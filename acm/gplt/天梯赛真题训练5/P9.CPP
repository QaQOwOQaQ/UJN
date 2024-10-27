#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 110;

int n;
struct node{
    string s;
    int num;
    double avg;
    node () {}
    node (string s1, int num1, double avg1) : s(s1), num(num1), avg(avg1) {}
}w[N];

bool cmp(node x, node y)
{
    if(x.num == y.num)  return x.avg < y.avg;
    return x.num > y.num;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        string str;
        int k;
        set<int> S;
        
        cin >> str >> k;
        for(int i = 0; i < k; i ++ )
        {
           int x;   cin >> x;
           S.insert(x);
        }
        int num = S.size();
        
        w[i] = {str, num, k};
    }

    sort(w, w + n, cmp);    
    // for(int i = 0; i < n; i ++ )
    // {
    //     cout << w[i].s << " " << w[i].num << " " << w[i].avg << endl;
    // }
    
    if(n < 3)
    {
        for(int i = 0; i < n; i ++ )
        {
            cout << w[i].s;
            if(i != n - 1)  cout << " ";
        }
        for(int i = n + 1; i <= 3; i ++ )
            cout << " -";
    }
    else
    {
        for(int i = 0; i < 3; i ++ )
        {
            cout << w[i].s;
            if(i != 2)  cout << " ";
        } 
    }
    
    return 0;
}