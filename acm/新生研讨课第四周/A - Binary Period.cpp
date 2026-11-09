#include<string>
#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>T;
	while(T--){
		k = 1;
		for(int i=0;i<s.length()-1;i++){
			if(s[i] != s[i+1]){
				k = 0;
				break;
			}	
		}
		if(k == 1)
			cout<<s<<endl;
		else{
			for(int i=0;i<s.length();i++){
				cout<<10; 
			}
			cout<<endl;
		}
	}	
	return 0;

} 

//	A - Binary Period
//	https://harris.blog.csdn.net/article/details/105788250?utm_medium=distribute.pc_relevant.none-task-blog-searchFromBaidu-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-searchFromBaidu-1.control

