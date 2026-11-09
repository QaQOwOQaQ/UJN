#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

const int base = 2;

int n;
int float_len;
string d;	// 题目保证d包含小数点 
string l, r;	// 小数点左侧和小数点右侧 
string sa;	// d去掉小数点 

vector<int> mul(vector<int> &a, int b)
{
	vector<int> c;
	int t = 0;
	for(int i = 0; i < a.size(); i ++ )
	{
		t += b * a[i]; 
		c.push_back(t % 10);
		t /= 10;
	}
	while(t)
	{
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}

vector<int> add(vector<int> &a, int b)
{
	vector<int> c;
	int t = b;
	reverse(a.begin(), a.end());
	for(int i = 0; i < a.size(); i ++ )
	{
		t += a[i];
		c.push_back(t % 10);
		t /= 10;
	}
	while(t)
	{
		c.push_back(t % 10);
		t /= 10;
	}
	reverse(c.begin(), c.end());
	return c;
}

void solve()
{
	int pos = d.find('.');
	l = d.substr(0, pos), r = d.substr(pos + 1);
	sa = l + r;
	float_len = d.size() - pos - 1;
	
	vector<int> a;
	for(int i = sa.size() - 1; i >= 0; i -- )	a.push_back(sa[i] - '0');
	for(int i = 0; i < n; i ++ )	a = mul(a, base);
	reverse(a.begin(), a.end());
	
	int first_float = a.size() - float_len;
	int first_float_value = a[first_float];
	a = vector<int>(a.begin(), a.begin() + first_float);
	if(first_float_value >= 5)		a = add(a, 1); 	
	
	for(int i = 0; i < a.size(); i ++ )	cout << a[i];
	cout << endl;
}

int main()
{
	cin >> n >> d;
	solve();
	return 0;
}


