#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int len;
	int flag;
	while(getline(cin,s))
	{
		flag=1;
		len=s.length();
		for(int i=0;i<len-2;i++)
		{
			if(s[i]=='M'&&s[i+1]=='M'&&s[i+2]=='M')
				flag=0;	
		} 
		if(flag==1)
			cout << "^v^";
		else
			cout << "==";
		cout << endl;
	}

	return 0;
}
