#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <unordered_map>

/*
    score:22
    TLE:test6
*/
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
string ming[N], xing[N];
unordered_set<string> ming_s;
unordered_map<string, int>sex;//0->man, 1->woman
unordered_map<string, string> pre;
unordered_map<string, bool> st;

bool get(string a, string b)
{
    int i = 1, j;
    for(string fa = a; st[fa]; fa = pre[fa], i ++ )
    {
        j = 1;
        for(string fb = b; st[fb]; fb = pre[fb], j ++ )
        {
            if(i >= 5 && j >= 5)    return true;
            if(fa == fb && (j < 5 || i < 5))   return false;
            if(j > 5)   break;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> ming[i] >> xing[i];
        ming_s.insert(ming[i]);
        if(xing[i][xing[i].length() - 1] == 'm')    sex[ming[i]] = 0;
        else if(xing[i][xing[i].length() - 1] == 'f')   sex[ming[i]] = 1;
        else if(xing[i][xing[i].length() - 1] == 'n')   
        {
            pre[ming[i]] = xing[i].substr(0, xing[i].length() - 4);
            sex[ming[i]] = 0;
        }
        else if(xing[i][xing[i].length() - 1] == 'r')   
        {
            pre[ming[i]] = xing[i].substr(0, xing[i].length() - 7);
            sex[ming[i]] = 1;
        }            
        st[ming[i]] = true;
    }
    
    cin >> m;
    while(m -- )
    {
        string m1, x1, m2, x2;
        cin >> m1 >> x1 >> m2 >> x2;
        if(!ming_s.count(m1) || !ming_s.count(m2))  puts("NA");
        else if(sex[m1] == sex[m2]) puts("Whatever");
        else if(get(m1, m2))  puts("Yes");
        else    puts("No");
    }

    return 0;
}
