#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,int> q;
	map<int,int>::iterator it;
	int N,T;
	int cost,t;
	cin >> N >> T;
	while(N--)
	{
		cin >> cost >> t;
		if(t<=T)
			q.insert(map<int,int>::value_type(cost,t));//»¨·ÑÉýÐò				
	}
	if(q.empty())
		cout <<  "TLE instead";
	else
		cout << q.begin()->first;
	return 0;
}
