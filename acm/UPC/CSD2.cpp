#include<iostream>
#include<algorithm>
using namespace std;
 
struct Ti{
	int s,e;
}t[200];
 
bool cmp(Ti a,Ti b){
	return a.e<b.e;
}
 
int main(){
	int n;
	while(cin>>n&&n){
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>t[i].s>>t[i].e;
		}
		sort(t,t+n,cmp);
		for(int i=0,j=1;j<n;j++){
			if(t[j].s>=t[i].e){
				i=j;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


