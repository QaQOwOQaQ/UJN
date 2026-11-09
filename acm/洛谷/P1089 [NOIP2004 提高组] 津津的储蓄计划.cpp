#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	int spend[12];	//花销
	int sum=0;	//存在妈妈哪里的钱
	int month=0;	//某个月的钱 
	for(int i=0;i<=11;i++)
		cin >> spend[i];
	for(int i=0;i<=11;i++)
	{
		month += 300 - spend[i];
		if(month<0)
		{
			cout << "-" << (i + 1) << endl;
			return 0;	
		}
			sum += month/100;	//sum个100 
			month = month - month / 100 * 100;			
//	cout << "month:" << month << endl;
//	cout << "monther:" << sum  << endl;		
	}

	cout << (month + sum * 120) << endl;


	return 0;
	
 } 
