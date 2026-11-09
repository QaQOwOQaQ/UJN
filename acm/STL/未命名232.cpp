#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<string>s1;///用于存储
stack<string>s2;///用于输出
int main()
{
    int t;
    scanf("%d",&t);
  //  while(!s1.empty()) s1.pop();
  //  while(!s2.empty()) s2.pop();
    while(t--)
    {
        string op;
        cin>>op;
        if(op[0] == 'p')
        {
            cout<<"/";
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            while(!s2.empty())
            {
                cout<<s2.top();
                s1.push(s2.top());///这个要加上去,因为我不会遍历栈的元素..
                s2.pop();
            }
            cout<<endl;
        }
        else
        {
            string a;
            cin>>a;
            int leno = a.length();
            a[leno++] = '/';
            a[leno] = '\0';
            string now;
            now = "";///取出每个单词,一种三种情况,对应题目的描述
            for(int i = 0; i < leno; i++)
            {
                now = now + a[i];
                if(a[i] == '/')
                {
                    if(now == "../")
                    {
                        if(!s1.empty()) s1.pop();///判断勿忘,返回一个文件夹
                    }
                    else if(now == "/")
                    {
                        while(!s1.empty()) s1.pop();///重新建立根目录,清空所有
                    }
                    else///在当前文件夹里新建文件夹
                    {
                        s1.push(now);
                    }
                    now = "";///清空勿忘
                }///文件夹是我这么说而已,为了便于理解,其实是目录的说....
            }
        }
    }
    return 0;
}
