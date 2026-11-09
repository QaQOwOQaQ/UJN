#include<iostream>
#include<string>
using namespace std;
int main(){
	int k,count,len[25];
	string s,ceshi;
	cin>>k>>s;
//	for(int i=0;i<s.length();i++)
//s.substr(pos,len) 截取字符串 
	if(k == 1)
		cout<<"Yes"<<endl<<s;
	else{
		count = 0; 		//可分组个数=count+1 
		for(int i=1;i<s.length();i++){
			for(count=0;count>0;count++){
				if(s[i]!=s[i-1] && s[i]!=ceshi[count]){
					ceshi[count] = s[i];
					count++;
				}	
			}
		}
	}
	if(count+1 >= k)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
 
