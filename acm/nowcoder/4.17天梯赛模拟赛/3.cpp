#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	double a, b, res = 0;
	int op;
	
	cin >> a >> op >> b;
	if(op == 1)	res = a * 1.26;
	else	res = a * 2.455;
	
	printf("%.2lf ", res);
	if(res <= b)	cout << "^_^";
	else	cout << "T_T";
	
	
	return 0;
}
