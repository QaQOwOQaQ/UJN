#include<iostream>
#include<cmath>
using namespace std;
//从键盘输入正整数n，编程计算并输出1~n各数字十位之和。
int main()
{
	int n;
	int ans=0;
	cin >> n;
	if(n<10)
		cout << ans;
	else
	{
		//12
		//100
		//132
		//1524
		//4564545654
		for(int i=10;i<=n;i++)
		{
			ans+=i/10%10;
		}
		cout << ans;	
	}

	return 0;
}
