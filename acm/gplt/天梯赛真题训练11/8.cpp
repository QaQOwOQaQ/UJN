#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int b[1010];
bool st[1010];

int main()
{
    cin >> n;
    int cnt = 0;
    int last = -1, times = 0, timelen = 0;
    
    while(1)
    {
        int id, hh, mm;
        char op;
        scanf("%d %c %d:%d", &id, &op, &hh, &mm);
        
        if(!id)//下一天了
        {
            cnt ++ ;
            if(!times)  cout << "0 0" << endl;
            else cout << times << ' ' << (int)(1.0 * timelen / times + 0.5) << endl;
            
            //初始化
            times = 0;
            timelen = 0;
            memset(st, 0, sizeof st);
        }
        
        else//同一天
        {
            if(op == 'S')   
            {
                b[id] = hh * 60 + mm;//测试点2,多次借书,以最后一次为准
                st[id] = true;
            }
            else//op == 'E'
            {
                if(!st[id]) continue;//没有借过
                timelen += (hh * 60 + mm) - b[id];
                times ++ ;
                st[id] = false;//测试点1,当我们归还一本书之后,就标记为没借过
            }
            last = hh * 60 + mm;
        }
        if(cnt == n)    break;
    }
    
    return 0;
}
/*
3
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00

0 S 17:00

3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00
*/