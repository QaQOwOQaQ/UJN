#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N=1e5;
string s;
long long int b;
long long int ans[N],a[N];
int main()
{
	cin>>s>>b;							//a是被除数  b是除数 
	int len=s.length();	
	for(int i=0;i<len;i++)
		a[i+1]=s[i]-'0';				//反序存储 
	
	//
	cout << "测试" << endl;
	for (int j=1;j<=len;j++)
		cout << a[j];
	cout << endl;
	
	
	
	//
	long long int tmp=0;				//所有中间的数都用longlong 
	for(int i=1;i<=len;i++)
	{
		a[i]+=tmp*10;					//累计前面剩的数 
		ans[i]=a[i]/b;					//如果不够除，因为都是整形数，就是0 
		tmp=a[i]-ans[i]*b;				//计算剩下的数 
	}
	int i;
	for(i=1;i<len;i++)
		if(ans[i]!=0)					//除0 
			break;
	for(;i<=len;i++)
		cout<<ans[i];					//输出 
	return 0;
}

