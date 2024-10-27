#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

inline int get(int x)
{
    return (long long)(1 + x) * x / 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(n == m)  puts("Draw");
    else if(!n || !m)//get 10%score需要特判，下面处理不了n或m为0的情况
    {
        if(!n)  cout << "Tari 0" << endl;
        else    cout << "Erini 0" << endl;
    }
    /*
    正解
    我们可以发现，每次走的距离构成一个等差数列
    如果总距离等于等差数列的和，那么时间就很好求了，因为不涉及到后退操作
    后退操作：
    后退后我们走的总距离肯定是增大的，并且这个距离仍然是等差数列的和
    这里其实不用证明，稍微看就能看出来，后退其实可以看作增加了总距离
    因为最后走的距离必须是一个等差数列，所以不管怎么后退，最后的距离肯定是大于当值距离的一个等差数列的和
    如果能看出来这一点，就非常接近答案了
    我们只需要在当前距离后面找一个距离他最近的Sn不久好了？
    不好！还需要判断奇偶性！
    就比如n=12吧，距离他最近的比他大的Sn是15
    但n不可能变为15，为什么？
    我们可以把后退操作想成这样一个过程：已经走了x，发现需要后退，那么我们要线后退一个x，退后原位置，然后还需要后退，这次是真的后退
    我们可以发现后退在这里进行了两次，也就是说后退的距离是偶数！
    而任何数+偶数还是原本的奇偶性！
    所以n=12时，只能走到28，前面的21和15都不可能走到
    至此，就分析完了
    */
    else//get 90%score
    {
        int t1 = 0, t2 = 0;
        for(int i = 0; i <= 1e5; i ++ )
        {
            if(t1 && t2)    break;
            int x = get(i);
            if(!t1 && x >= n)
            {
                for(int j = i; !t1 ;j ++ )
                    if((get(j) & 1) == (n & 1))
                        t1 = j;
            }
            if(!t2 && x >= m)
            {
                for(int j = i; !t2 ;j ++ )
                    if((get(j) & 1) == (m & 1))
                        t2 = j;
            }
        }
        if(t1 == t2)    cout << "Draw" << endl;
        else
        {
            if(t1 < t2) cout << "Tari ";
            else    cout << "Erini ";
            cout << min(t1, t2) << endl;  
        }
    }
    
    /*
    //一种错误想法，但得到了50%的分，奇怪=。=
    else
    {
        int t1 = 0, t2 = 0;
        for(int i = 1; n || m ; i ++ )
        {
            if(n)
            {
                n -= i;
                if(n < 0)   t1 ++ , n = 0;
                t1 ++ ;
            }
            if(m)
            {
                m -= i;
                if(m < 0)   t2 ++ , m = 0;
                t2 ++ ;
            }
        }
        if(t1 == t2)    cout << "Draw" << endl;
        else if(t1 < t2) cout << "Tari ";
        else    cout << "Erini ";
        if(t1 != t2)    cout << min(t1, t2) << endl;
    }
    */
    return 0;
}