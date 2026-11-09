#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[100010];
	cin>>s;
	int len = strlen(s);
	for(int i=0;i<24+len;i++)
		cout << "*";
	cout << endl;
	cout << "*Welcome,ContestantNo.";
	cout << s;
	cout << "!*" << endl;
	for(int i=0;i<24+len;i++)
		cout << "*";
	return 0;
}
