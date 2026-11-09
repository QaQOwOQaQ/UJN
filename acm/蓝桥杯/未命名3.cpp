//计算1-2020年有多少年含有数字2！ 
#include<iostream>
#include<string>
using namespace std;
int main()
{
		int sum=0; 
	for(int i=1;i<=2020;i++)
	{
		if(i>=1&&i<=99)
		{	//42.24
			if( (i%10==2) || (i/10==2) )
			sum++;
		}
		else if(i<=999)
		{	//245.425.542.205
			if( (i/100==2) || (i%100/10==2) || (i%100%10==2) )
				sum++;
		}
		else
		{
			//2013.1203.1320.1302
			if( (i/1000==2) || (i%1000/100==2) || (i%1000%100/10==2) || (i%1000%100%10==2) )
				sum++; 
		}	
	}
	printf("%d",sum);
}



