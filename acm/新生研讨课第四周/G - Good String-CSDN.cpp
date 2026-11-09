#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k=0;
    string s;
    	cin >> n;
        cin >> s;
        for(int i=0;i<s.length()-1;i++)//到n-1不能超范围
        {
            if(s[i]==s[i+1])
            {
                s[i]='#';//标记不输出
                k++;//删除数量+1
            }
            else
            {
                i++;
            }
        }
         if((n-k)%2!=0)//长度为奇数
        {
            k++;
            cout << k << endl;
            for(int j=n-1;j>=0;j--)//把最后一位标记为#不输出
            {
                if(s[j]!='#')
                {
                    s[j]='#';
                    break;
                }
            }
        }
        else{
            cout << k << endl;
        }

            for(int j=0;j<n;j++)
            {
                if(s[j]!='#')
                {
                    cout << s[j];
                }
            }
        cout << endl;
     return 0;
}

