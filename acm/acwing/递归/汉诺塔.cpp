#include<iostream>
#include<cmath>

using namespace std;

//void hnt(int n,char a,char b,char c)//star;tmppoar;goal
//{
//	if(n==1)
//	{
//		cout << a << "->" << c << endl;
//	return ;
//	}
//	else
//	{
//		hnt(n-1,a,c,b);	
//		hnt(1,a,b,c);
//		hnt(n-1,b,a,c);
//	}
//	return ;
//	
//}

void hnt(int n,char a,char b,char c)
{
	if(n == 1)
	{
		cout << a << " -> " << c << endl; 
		return ;		
	}

	else
	{
		return hnt(n-1,a,c,b);
		return hnt(1,a,b,c);
		return hnt(n-1,b,a,c);
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	cout << (pow(2,n) - 1) << endl;
	hnt(n,'a','b','c');
	
	
	return 0;
} 
