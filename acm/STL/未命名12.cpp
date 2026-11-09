#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for(int j=0;j<T;j++)
	{
		char a[500];
		long long b;
		cin>>a>>b;
		int l=strlen(a);
		long long ans=0;
		for(int i=0;i<l;i++)
		{
			if(a[i]=='-') 
				continue;
			ans=((ans*10)+a[i]-'0')%b;
		}
	if(ans == 0)
		cout << "Case " << j+1 << ": divisible" << endl;
	else
		cout << "Case " << j+1 << ": not divisible" << endl;
	}
	return 0;
} 

