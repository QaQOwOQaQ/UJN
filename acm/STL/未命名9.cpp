
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long LL;
set<string >dict;
int main()
{
    string s,buf;
    while(cin>>s){
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i]))//isalpha是判断当前字符是否为字母，是返回true，不是返回false
            s[i]=towlower(s[i]);//towlower是对于字母将当前字母转换成小写字母
        else
            s[i]=' ';//不是字母就用空格表示
        stringstream ss(s);//创建存储s的副本的stringstream对象，其中s是ss的类型对象，提供读写string的功能
        while(ss>>buf)//将ss插入到buf中。如果是ss<<buf 则是讲buf输入到流。
            dict.insert(buf);
    }
     for(set<string >::iterator it=dict.begin();it!=dict.end();it++)
            cout<<*it<<endl;
    return 0;
}


