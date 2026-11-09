#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main()
{
		string s;
		cin >> s;
		if(s == "0")
		{
			cout << 0;
			return 0;
		}
		if(s[0] == '-')	
		{
			cout << '-';
			s[0] = 'X';			
		}

		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i] == '0')
				s[i] = 'X';
			else
				break;
		}
		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i] != 'X')
				cout << s[i];
		}
	
	
	cout << endl;
	return 0;
}
