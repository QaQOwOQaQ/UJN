#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> table;
	int n,m;
	while(cin >> n >> m)	//2n个人，间距m 
	{
		table.clear();
		for(int i=0;i<2*n;i++)
			table.push_back(i);
		int pos = 0;	//记录当前位置
		for(int i=0;i<n;i++)
		{
			pos = (pos + m - 1) % table.size();
			table.erase(table.begin() + pos);
		}
		
		int j = 0;
		for(int i=0;i<2*n;i++)
		{
			if(!(i%50) && i)	//否则i=0时会输出空行 
				cout << endl;
			if(i==table[j] && j<table.size())
			{
				j++;	cout << "G";
			}
			else
				cout << "B";
		}
		cout << endl << endl;
	
//	for(int i=0;i<2*n;i++)
//		cout << table[i] << " ";
//	cout << endl;

	}	
	
	return 0;
}


