#include<iostream>
#include<cstring>
#include<set>
#include<algorithm> 
using namespace std;
//用于字符排序 
char r[8];
//用于存储总的路径数 
int ans;
//用于表示当前点的状态 
bool dp[3][3];
//用于描述点的值 
char a[3][3]={{'a','b','\0'},{'f','g','c'},{'\0','e','d'}};
//用于上下左右移动 
int b[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
//用于去重 
set<string> t;
//用于判断访问点是否越界 
bool in(int x,int y){
	return x>=0&&x<3&&y>=0&&y<3;
}
//用于删除空格，并将字符排序 
void deletespace(string ss){
	for(int i=0;i<8;i++){
		r[i]='\0';
	}
	int m=0;
	int lena=ss.length();
	for(int i=0;i<lena;i++){
		if(ss[i]!='\0'){
			r[m++]=ss[i];
		} 
	}
	sort(r,r+m);
}
//用于搜索全部路径
//x,y用于存放当前点的坐标
//ss用于记录当前路径 
void dfs(int x,int y,string ss){
	dp[x][y]=true;
	for(int i=0;i<4;i++){
		int tx=x+b[i][0];
		int ty=y+b[i][1];
		if(in(tx,ty)&&!dp[tx][ty]){ 
			ans++;
			deletespace(ss+a[tx][ty]);
			t.insert(r);
			//可以用于输出全部路径 
			cout<<r<<endl;
			dfs(tx,ty,r);
		}
	}
	dp[x][y]=false;
}
int main(){
	//整体思路讲解
	//1.从每个点都要出发一次
	//2.ans表示路径数 ss表示当前路径字符串 
	//3.deletespace可以删除当前路径字符串中的'\0'，同时将字符串内部从小到大排序，存储在char r[8];中 
	//4.将处理完后的字符串保存到集合中，因为集合具有自动去重功能 
	//5.输出集合大小，即为路径总数 
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(a[i][j]!='\0'){
				ans++;
				string ss="";
				ss+=a[i][j];
				deletespace(ss);
				t.insert(r);
				cout<<r<<endl;
				dfs(i,j,r);	
			}	
		}
	}
	cout<<"总路径数为:(总路径数包括重复路径，因此需要去重)"<<ans<<endl;
	cout<<"---------------------------------------------------------"<<endl; 
	for(set<string>::iterator it=t.begin();it!=t.end();it++){
		cout<<*it<<endl;
	}
	cout<<"去重之后的实际路径数:"<<t.size()<<endl;
	return 0;
}

