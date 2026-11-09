#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int n,score,a[3],flag,forward=0,ans=0;
	cin >> n;
	while(n--)
	{
		cin >> score;
		s.push(score);	
	}
	for(int i=0;i<3;i++)
		cin >> a[i];
	cin >> flag;
	forward = a[3-flag];
	while(!s.empty())
	{
		if(s.top()>=forward)
			ans++;
		s.pop();
	}
	cout << ans;
	return 0;
}
