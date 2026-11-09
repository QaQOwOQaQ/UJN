#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct pation
{
	int v;
	int num;
}s;

bool operator <(const pation &x,const pation &y)
{
	if(x.v == y.v)
		return x.num>y.num;
	else
		return x.v<y.v;
}
int main()
{
	int n;
	while(cin >> n)
	{
		priority_queue<pation> p[4];
		int k = 1;
		for(int q=0;q<n;q++)
		{
			string str;
			int d,val;	//doctor,value
			cin >> str >> d;
			if(str == "IN")
			{
				cin >> val;
				s.v = val;
				s.num = k++;
				p[d].push(s);
			}
			else
			{
				if(p[d].empty())
					cout << "EMPTY" << endl;
				else
				{
					cout << p[d].top().num << endl;
					p[d].pop();

				}
			}
		}
		
	}
	
	return 0;
}
