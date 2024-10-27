#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    getchar();  //好恶心啊！！！
    
    for(int i = 1; i <= n; i ++ )
    {
        string s;
        getline(cin, s);
        if(s.find("easy") == -1 && s.find("qiandao") == -1)       
        {
            m -- ;
            if(m < 0) 
            {
                cout << s << endl;
                return 0;
            }
        }
    }
    puts("Wo AK le");

    
    return 0;
}