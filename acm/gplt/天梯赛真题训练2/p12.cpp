#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10100;

int a[N];
int n, m;

void down(int x)
{
    int t = x;  //min_number
    if(x * 2 <= n && a[x * 2] < a[t]) t = x * 2;
    if(x * 2 + 1 <= n && a[x * 2 + 1] < a[t])   t = x * 2 + 1;
    if(t != x)
    {
        swap(a[t], a[x]);
        down(t);
    }
}

void up(int x)
{
    int t = x;
    if(x / 2 && a[x / 2] > a[t])    t = x / 2;
    if(t != x)
    {
        swap(a[t], a[x]);
        up(t);
    }
}

int get(int x)
{
    for(int i = 1; i <= n; i ++ )
        if(a[i] == x)   return i;
        
    return -1;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )   //一个坑点,题目要求的是按给定数组的顺序构建堆
    {
        cin >> a[i];
        up(i);
    }
    
    // cout << "heap: ";
    // for(int i = 1; i <= n; i ++ )   cout << a[i] << " ";
    // cout << endl;
    
    while(m -- )
    {
        int a, b;
        string s;
        cin >> a >> s;
        
        a = get(a);
        if(s == "and")  //(1)a and b are siblings
        {
            string s1, s2;
            cin >> b >> s1 >> s2;
            b = get(b);
            // cout << "(1): ";
            if(a / 2 == b / 2)  puts("T");
            else    puts("F");
        }
        else // s = "is"
        {
            string s1, s2, s3;
            cin >> s1;
            if(s1 == "a")   //(2)a is a child of b
            {
                cin >> s2 >> s3 >> b;
                b = get(b);
                // cout << "(2): ";
                if(a / 2 == b)  puts("T");
                else    puts("F");
            }
            else  // s = "the"
            {
                cin >> s2;
                if(s2 == "root")//(3)a is the root
                {
                    // cout << "(3): ";
                    if(a == 1)  puts("T");
                    else    puts("F");
                }
                else //(4)a is the parent of b
                {
                    cin >> s3 >> b;
                    b = get(b);
                    // cout << "(4): "; 
                    if(b / 2 == a)  puts("T");
                    else    puts("F");
                }
            }
            
        }
        
    }

    return 0;
}