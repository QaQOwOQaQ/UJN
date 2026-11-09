#include<iostream>
using namespace std; 
int main()
{
	char s[4];
	int n;
	cin >> n;
	while(n--)
	{
		int c=0,d=0,a=0;
		cin >> s;	
		for(int i=0;i<4;i++)
		{
			if(s[i]=='A')
				a++;
			if(s[i]=='C')
				c++;
			if(s[i]=='D')
				d++;
		}
		if(d>0 || c>=2)
			cout << "failed" << endl;
		else if(a>=3)
			cout << "sp offer"<< endl;
		else
			cout << "offer"<< endl;
	}

	return 0;
}
