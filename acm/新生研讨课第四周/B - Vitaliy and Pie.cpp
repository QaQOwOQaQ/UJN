#include<string>
#include<iostream>
using namespace std;
int main(){
	int T,n=0;				//门数量
	string s;		
	cin>>T;
	cin>>s;
	for(int i=0;i<s.length();i++){		//统一小写 
		if(s[i]>='A' && s[i]<='Z')
			s[i] = s[i]+32;
	}
	//cout<<s<<endl;
	
	
	for(int i = 0;i<s.length()-1;i = i+2){
		if(s[i] == s[i+1]){
	//		n = n + 0;
			s[i] = '#';				//定义药匙为空 
		}   				 
		else if(i == 0)
			n = n + 1; 
		else{
			int m=0;					//判断能否能用之前的药匙打开门：1-能 
			for(int j=0;j<i;j=j+2){		//0,2,4....
				if(s[j] == s[i+1]){
					s[j] = '#';
					m = 1;
					break;
				}
			}
			if(m == 0)
				n = n + 1;
		}
	
	}
	cout<<n;
	return 0;

} 

