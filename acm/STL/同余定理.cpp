#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[100];
	int T,b,len;
	cin >> T;
//	len = sizeof(a);  //wrong!!! 
	for(int j=0;j<T;j++)
	{	
		long long ans = 0;
		cin >> a >> b;
		len = strlen(a);
			for(int i=0;i<len;i++)
		{
			if(a[i]=='-')
				continue;
			else
				ans = (ans*10+(a[i]-'0'))%b;
		}
	if(ans == 0)
		cout << "Case " << j+1 << ": divisible" << endl;
	else
		cout << "Case " << j+1 << ": not divisible" << endl;		
	}
} 
