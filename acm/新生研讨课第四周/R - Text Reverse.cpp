#include<bits/stdc++.h>
using namespace std;
int main(){
	int	T,len,flat;
	string s;
	cin >> T;
	getchar();
	while(T--){
		cin >> s;
		flat = 0;
		len = s.length();
		for(int i=0;i<len;i++){
			if(s[i] == ' '){
				for(int j=i-1;j>=flat;j--)
					cout << s[j];
				flat = i + 1;
				cout << " " ;
			}
		if(i == len-1){	
		   	for(int h=i;h>=flat;h--)
		   		cout << s[h];
		   }
		}
		cout << endl;
	}
	return 0;
}
