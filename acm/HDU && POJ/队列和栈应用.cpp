#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{ 
		queue<int> v;
		stack<int> st;
		int m;
		string s;
		cin >> m >> s;
		if(s == "FIFO")	//∂”¡– 
		{
			for(int j=0;j<m;j++)
			{
				string ops;
				int op;
				cin >> ops;
				if(ops == "IN")
				{
					cin >> op;
					v.push(op);		
				}
				else
				{
					if(v.empty())
						cout << "None" << endl;
					else
					{
						cout << v.front() << endl;
						v.pop();						
					}				
				}
			}			
		}
		else	//’ª 
		{
			for(int j=0;j<m;j++)
			{
				string ops;
				int op;
				cin >> ops;
				if(ops == "IN")
				{
					cin >> op;
					st.push(op);		
				}
				else
				{
					if(st.empty())
						cout << "None" << endl;
					else
					{
						cout << st.top() << endl;
						st.pop();							
					}
				
				}
			}						
		} 
	}

	return 0;
}
