#include<bits/stdc++.h>
using namespace std;
//F雷达总是说“拉拉”在句子结尾时，
//彩虹总是说“苗”在他的句子开头。
int main()
{	int n,len;
	int x,y;  //freda,rainbow;
	string s,a,b;
	cin >> n;
	getchar();
	while(n--)
	{	getline(cin,s);
		x = 0;
		y = 0;
		len = s.length();
//		cout << s << endl << len;	
		if(len<5)
			cout << "OMG>.< I don't know!" << endl;
		if(len == 5 && s != "miao.")
			cout << "OMG>.< I don't know!" << endl;
		else
		{	
			a = s.substr(0,5);
			b = s.substr(len-5,5);
//			cout << a << endl << b ;
			if(a == "miao.")
				x = 1;
			if(b == "lala.")
				y = 1;
//			cout << x << y << endl ;
		
		if(x==1&&y==0)
			cout <<  "Rainbow's" << endl;
		else if(x==0&&y==1)
			cout <<  "Freda's" << endl;
		else
			cout << "OMG>.< I don't know!" << endl;
		}
	}	
	return 0;
} 
