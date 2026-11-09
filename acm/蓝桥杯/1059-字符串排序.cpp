#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string str[1010];
int main()
{
	int n;
	cin >> n;
	string t;
	for(int j=0;j<n;j++)
	{
		cin >> str[j];
		for(int i=0;i<str[j].length();i++)
		{
			if(str[j][i]>='A' && str[j][i]<='Z')
				str[j][i] = str[j][i] + 32;
			else
				str[j][i] = str[j][i] - 32;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(str[i] > str[j])
			{
				t = str[i];
				str[i] = str[j];
				str[j] = t;
			}
		}
	}
		
	for(int i=0;i<n;i++)
	{
		cout << str[i] << endl;
	}
}
