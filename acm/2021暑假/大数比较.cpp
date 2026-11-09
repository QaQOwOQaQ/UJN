#include <iostream>
using namespace std;
typedef long long ll;
ll x,y,a,b;
int main(){
	while(~scanf("%lld%lld%lld%lld",&x,&a,&y,&b)){
		//判断整数部分
		if(x/a>y/b)	printf(">\n");
		else if(x/a<y/b)	printf("<\n");
		//判断小数部分，交叉相乘
		else{
			x=x%a;
			y=y%b;
			if(b*x>a*y)	printf(">\n");
			else if(b*x<a*y)	printf("<\n");
			else printf("=\n");
		}
	}
	return 0;
}

