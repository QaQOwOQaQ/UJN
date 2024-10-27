#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

using namespace  std;

const int N = 100010;

int n, m, k;
stack<int> v;
stack<int> w;
int a[N];
vector<int> res;
int last = -1;

void out()
{
	if(!res.size())	return ;
	
//	cout << "out" << endl;
 	for(int i = 0; i < res.size(); i ++ )
	{
		cout << res[i];
		if(i != res.size() - 1)	cout << ' ';
		else	cout << endl;
	}
	res.clear();
	last = -1;
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++ )	cin >> a[i];
	
	for(int i = n; i >= 1; i -- )	w.push(a[i]);
	
	while(w.size() || v.size())
	{
		if(last == -1)
		{
			if(v.size())	
			{
				res.push_back(v.top());
				last = v.top();
				v.pop();
			}
			else
			{
				res.push_back(w.top());
				last = w.top();
				w.pop();
			}
		}
		else//last != -1
		{
			if(v.size() && v.top() <= last)
			{
				res.push_back(v.top());
				last = v.top();
				v.pop();
			}
			else
			{
				while(w.size() && w.top() > last)
				{
					if(v.size() < m)	v.push(w.top()), w.pop();
					else	
					{
//						cout << "last: " << last << endl;
						break;	
					}
				}
				if(w.size() && w.top() <= last)
				{
					res.push_back(w.top());
					last = w.top();
					w.pop();
				}
				else	out();
			}
		}
		if(res.size() == k)	out();
	}
	
	out();
	
	
	return 0;
}
