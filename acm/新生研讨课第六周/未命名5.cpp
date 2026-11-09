#include<bits/stdc++.h>  
#include<stack>
using namespace std;
int main(){
	 int n;
	 char ch;
	 cin>>n;
	 getchar();
	 while(n--){
	  	stack<char>s;		//定义栈
	 	 while(1){
	  	 ch=getchar();		//一次读入一个字符
	   	 if(ch == ' '||ch =='\n')
	{
	   	 while(!s.empty()){	//检查栈是否为空
	     		cout<<s.top(); //输出栈顶；
	    		 s.pop();  //清除栈顶； 出栈是必须进行两步操作，先top再pop
	   	 }
	    	if(ch=='\n')
	   	 break;
	   	 cout<<" "; 
	}
	   else
	    s.push(ch);   //放入栈顶； 
	  }
	  //cout<<endl; 
 	}
	 return 0;
}


