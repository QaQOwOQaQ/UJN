/*
一个容易犯的错误
1-11 != 11-1 
但如果将等式两边的两个整数直接连接在一起形成一个字符串
就变成了 111==111
这是不对的！
因为需要规范成（假设整数的位数一共两位）:01-11 != 11-01
这样转换成字符串就是：0111 != 1101
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 21000;

int n, m;

struct Node{
    string id;
    string num;
}node[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
    {
        string num, id = "";
        for(int j = 0; j < m; j ++ )
        {
            int a;   cin >> a;   
            string t = to_string(a);
            while(t.length() < 10)  t = "0" + t;
            id += t;
        }
        cin >> num;
        node[i] = {id, num};
    }
    
    int s;
    while(cin >> s, s)
    {
        string id = "";
        
        string tt = to_string(s);
        while(tt.length() < 10)  tt = "0" + tt;
        id += tt;
        
        bool has_res = false;
        
        for(int j = 0; j < m - 1; j ++ )
        {
            int a;   cin >> a;   
            string t = to_string(a);
            while(t.length() < 10)  t = "0" + t;
            id += t;
        }

        for(int j = 0; j < n; j ++ )
        {
            if(node[j].id == id)
            {
                cout << node[j].num << endl;
                has_res = true;
            }
        }
        if(!has_res)    cout << "Pass" << endl;
    }
    
    return 0;
}