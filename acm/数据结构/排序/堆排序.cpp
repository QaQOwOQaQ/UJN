#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int a[N], n, k, s;

void down(int x)	//下沉操作,将较大的数放到(最下面)也就是数组最后面 
{
	int t = x;
	if((x * 2) <= s && a[t] > a[x * 2])	t = x * 2;
	if((x * 2 + 1) <= s && a[t] > a[2 * x + 1])	t = x * 2 + 1;
	if(t != x)
	{
		swap(a[t], a[x]);
		down(t);
	}
}

int main() 
{
	cin >> n >> k;	//输入n个数,输出前k小的数 
	
	s = n;	
	/*保存当前堆的大小，因为我们每输出一个最小值都要把这个元素移除堆
	  所以堆的大小是动态变化的*/
	
	for(int i = 1; i <= n; i ++ )	cin >> a[i];
	for(int i = n / 2; i >= 0; i -- )	down(i);	//初始化堆 
	
	for(int i = 1; i <= n; i ++ )	cout << a[i] << " ";
	cout << endl;
	
	for(int i = 1; i <= k; i ++ )
	{
		cout << a[1] << " ";
		a[1] = a[s --];	//将最后一个元素放到根节点 
		down(1);	//下沉根节点 
	}
	cout << endl;
	
	return 0;
	
}

 
