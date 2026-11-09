#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int n,a;
	char num[100];
	while(scanf("%d",&n))
	{
		itoa(n,num,2);
		printf("%s\n",num);
	}
  
    return 0;
}

