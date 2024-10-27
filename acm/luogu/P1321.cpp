#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

string s;
int boy, girl;
unordered_map<char, char> follow = {
    {'.', '.'},
    {'b','o'}, {'o', 'y'}, {'y', '.'}, 
    {'g', 'i'}, {'i', 'r'}, {'r', 'l'}, {'l', '.'}
};

// 思路：找新单词的头

int main()
{
    cin >> s;
    boy = girl = 0;
    s = "." + s;    // 避免special check
    for(int i = 1; i < s.size(); i ++ ) 
    {
        if(s[i] != follow[s[i - 1]])
        {
            if(string("boy").find(s[i]) != -1)    boy ++ ;
            else    girl ++ ;
        }
    }
    // cout << s << ':' << boy << ' ' << girl << endl;
    cout << boy << endl << girl << endl;
    
    return 0;
}
