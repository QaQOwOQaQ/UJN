#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+7;

int t[N],a[N],n,m;
int main()

{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],t[i]=a[i];

	sort(t+1,t+n+1);
  
	//不相同元素个数 
	m=unique(t+1,t+n+1)-t-1;//因为这里多包涵了t[0]的地址，实际上数组地址(*t+0)这里是没有存放元素的，所以要减去（t+1) 
	cout << "m:" << m << endl;
  
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(t+1,t+1+m,a[i])-t;
    
    //离散化之后的结果 
    for(int i=1;i<=n;i++)
    	cout << a[i] << " ";
}
