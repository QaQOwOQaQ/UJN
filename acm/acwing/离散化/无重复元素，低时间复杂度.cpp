#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+7;
int order[N];

struct Node
{
	int v,id;
	bool operator < (const Node a)const{
		return v < a.v;
	}//ÅÅÐòÓÃ
}a[N];

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].v;
		a[i].id = i;
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
		order[a[i].id] = i;
	
	for(int i=1;i<=n;i++)
		cout << order[i] << " ";
	cout << endl;	
}
