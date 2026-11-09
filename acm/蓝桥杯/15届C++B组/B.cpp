//  TODO 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;

const int m = 343720, n = 233333;

int main()
{
	double t1 = 233333 * 1.0 / 17; 
	cout << t1 << endl;
	int y1 = t1 * 15;
	cout << y1 << endl;	
	int y2 = 343720 - y1;
	double t2 = y2 * 1.0 / 15;
	printf("%.3lf\n", t2);
	double x1 = t2 * 17;
	cout << x1 << endl;
	return 0;
}

