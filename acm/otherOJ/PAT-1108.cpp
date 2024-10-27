#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

#define x first
#define y second

#define debug2(x, y)	\
	cout << "debug: " << #x << " = " << x << "   " << #y << " = " << y << endl
#define debug1(x)	\
	cout << "debug: " << #x << " = " << x << endl
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int T;
int w[10];

bool check()
{
	for(int i = 0; i < 6; i ++ )
		if(w[i])
			return true;
	return false;
}

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i ++ )
	{
		if(s[i] == 'S')	w[0] ++ ;
		if(s[i] == 't')	w[1] ++ ;
		if(s[i] == 'r')	w[2] ++ ;
		if(s[i] == 'i')	w[3] ++ ;
		if(s[i] == 'n')	w[4] ++ ;
		if(s[i] == 'g')	w[5] ++ ;
	}
	
	while(check())
	{
		if(w[0])	cout << 'S', w[0] -- ;	
		if(w[1])	cout << 't', w[1] -- ;	
		if(w[2])	cout << 'r', w[2] -- ;
		if(w[3])	cout << 'i', w[3] -- ;
		if(w[4])	cout << 'n', w[4] -- ;
		if(w[5])	cout << 'g', w[5] -- ;
	}
	cout << endl;
	

    return 0;
}
