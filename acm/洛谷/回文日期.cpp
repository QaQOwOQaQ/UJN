#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int func(string s)	//判断是否是回文 
{
	if(s[0]==s[7] && s[1]==s[6] && s[2]==s[5] && s[3]==s[4])
	{
		cout << "回文数：" << s;
		return 1;		
	}

	else
		return 0;
}
int run(int year)	//判断闰年 
{
	if(year%400==0 || (year%4==0&&year%100!=0))
		return 1;
	else
		return 0;
}
string link(int y,int m,int d)	//需要判断的字符串 
{
	string year = to_string(y);
	string month = to_string(m);
	string day = to_string(d);
	while(month.length()<2)
		month.insert(0,"0");
	while(day.length()<2)
		day.insert(0,"0");
	string ans = year + month + day;
	return ans;
}
int main()
{
	string s1,s2,op;
	int y1,y2,m1,m2,d1,d2;	
	ll ans = 0;
	cin >> s1 >> s2;
	y1 = stoi(s1.substr(0,4),0,10);
	m1 = stoi(s1.substr(4,2),0,10);
	d1 = stoi(s1.substr(6,2),0,10);
	
//	cout << "初始值:" << endl; 
//	cout << y1 << " " << m1 << " " << d1 << endl;

	y2 = stoi(s2.substr(0,4),0,10);
	m2 = stoi(s2.substr(4,2),0,10);
	d2 = stoi(s2.substr(6,2),0,10);
	cout << y2 << " " << m2 << " " << d2 << endl;
	while(!(y1==y2 && m1==m2 && d1==d2))
	{
		d1+= 1;
		//2月		
		if( d1==30 && y1==2 && run(y1) )	//闰年 
		{
			d1 = 1;
			y1+= 1;
		}
		if( d1==29 && y1==2 && !run(y1) )	//非闰年 
		{
			d1 = 1;
			y1+= 1;
		}
		//4,6,9,11
		if( d1==31 && (y1==4 || y1==6 || y1==9 || y1==11) )
		{
			d1 = 0;		
			m1+= 1;	
		}
		//1,3,5,7,8,10,12
		if( d1==32 && (y1==1 || y1==3 || y1==5 || y1==7 || y1==8 || y1==10 || y1==12) )
		{
			d1 = 1;
			m1+= 1;
		}
		if(m1 == 13)
		{
			m1 = 1;
			y1+= 1;
		}
//		cout << y1 << " " << m1 << " " << d1 << endl;
		string op = link(y1,m1,d1);
//		cout << "日期:" << op << endl;
		ans+= func(op);
	}
	cout << ans << endl;
	return 0;
 } 
