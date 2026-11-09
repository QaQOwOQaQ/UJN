#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], c[N], n, cnt; 

void merge_sort(int b, int e)
{
	if(b >= e)	return ;
	
	int mid = b + e >> 1, i = b, k = b, j = mid + 1;
	merge_sort(b, mid);
	merge_sort(mid + 1, e);
	
	while(i <= mid && j <= e)
	{
		if(a[i] <= a[j])	c[k ++ ] = a[i ++ ];
		else	c[k ++ ] = a[j ++ ], cnt += mid - i + 1;
	}
	
	while(i <= mid)	c[k ++ ] = a[i ++ ];
	while(j <= e)	c[k ++ ] = a[j ++ ];
	
	for(int l = b; l <= e; l ++ )	a[l] = c[l];
	
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )	cin >> a[i];
	
	merge_sort(0, n - 1);
	
	for(int i = 0; i < n; i ++ )	cout << a[i] << " ";
	cout << endl;
	
//	cout << "ÄæÐò¶Ô¸öÊý£º" << cnt << endl; 
	
	return 0;
} 
