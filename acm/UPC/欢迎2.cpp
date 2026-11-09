#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int n=s.length();
	//第一行
	for(int i=0;i<24+n;i++)
	printf("*");
	printf("\n");
	
	//第二行
	printf("*");
	printf("Welcome,ContestantNo.");
	cout << s;
	printf("!*\n");
	
	//第三行
	for(int i=0;i<24+n;i++)
	printf("*");

	return 0;
	
}

