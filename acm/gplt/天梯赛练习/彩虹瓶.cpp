#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, m, q;

int main()
{
    cin >> n >> m >> q;
    while(q -- )
    {
        bool flag = true;
        stack<int> st;
        int now = 1;
        
        for(int i = 0; i < n; i ++ )    
        {
            int x;  cin >> x;
                      if(x == now)    now ++ ;
            else    st.push(x);
            if(st.size() > m)   flag = false;
            while(st.size() && st.top() == now) now ++ , st.pop();
        }        
        
        if(!flag || !st.empty())    cout << "NO" << endl;
        else    cout << "YES" << endl;
        
    }
    
    
    return 0;
}

/*
当一种颜色装填完以后，先看看货架顶端的一箱是不是下一个要装填的颜色！！
这句话理解可能会出差错
他的意思是，如果货架上的瓶子正好是下一个，可以一直拿，直到瓶子颜色不符合
例如：7532146
货架上放了7-5-3-2
当1放完之后，我们会从货架上连续拿走2，3，而不是只拿走一个2                     
/*