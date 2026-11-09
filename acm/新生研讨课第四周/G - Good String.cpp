#include<bits/stdc++.h>
using namespace std;
int main(){	
	int n,k=0;
	string s;
	cin>>n;
	cin>>s;
	//aaccd
	if(n == 0)
		cout<<k<<endl; 
	else{
		for(int i=0;i<s.length()-1;i=i+2){
			while(s[i] == s[i+1]){
				k++;
				s=s.substr(1,s.length()-1);
			}
		}
		if(s.length() % 2 != 0){
			k++;
			s=s.substr(0,s.length()-1);   
		}
		cout<<k<<endl<<s;
	}	
	return 0;
} 
