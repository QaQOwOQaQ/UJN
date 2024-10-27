#include <iostream>
#include <algorithm>
#include <cstring>

using namespace  std;

int main()
{
	int a, b;
	cin >> a >> b;
	long long res = 1;
	for(int i = 1; i <= a + b; i ++ )
		res = (long long)res * i;
	cout << res << endl;
	
	return 0;
}
