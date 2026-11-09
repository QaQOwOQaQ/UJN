#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	map<int,int> stu;
	map<int,int>::iterator it;
	int n,score,flag,N;
	cin >> n;
	N=n;
	while(n--)
	{
		cin>>score;
		stu[score]=0;;
	}
	flag=1;
	for(it=stu.begin();it!=stu.end();it++,flag++)
	{
		if(flag==N)
			cout << it->first;
		else
			cout << it->first<<" ";	
	}

	return 0;
 } 
