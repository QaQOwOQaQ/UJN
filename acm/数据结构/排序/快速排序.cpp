#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], n;

void quick_sort(int l, int r)  //j
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (a[i] < x);
        do j -- ; while (a[j] > x);
        if (i < j) 
            swap(a[i], a[j]);
    }
    quick_sort(j + 1, r); //如果以j作为端点划分区间,那么区间要分成[l,j]和[j+1,r],因为j的右侧一定是满足q[j]>=x的,但q[j-1]就不确定了,所以区间不能划分成[l,j-1]和[j,r]
    quick_sort(l, j);
   
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )	cin >> a[i];
	
	quick_sort(0, n - 1);
	
	for(int i = 0; i < n; i ++ )	cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
