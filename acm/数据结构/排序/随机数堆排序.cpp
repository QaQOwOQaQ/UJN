#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int N = 20, MAX = 100;

int rand_int[N], k, s;

void init()
{
	s = 10;
	for(int i = 1; i <= s; i ++ ) 
		rand_int[i] = 1 + rand() % MAX;
		
	cout << "Random Numbers: ";
	for(int i = 1; i <= 10; i ++ )	cout << rand_int[i] << " ";
	cout << endl;
}

void down(int x)
{
	int t = x;
	if((x * 2) <= s && rand_int[x * 2] < rand_int[t]) t = 2 * x;
	if((x * 2 + 1) <= s && rand_int[x * 2 + 1] < rand_int[t])	t = x * 2 + 1;	
	if(t != x)
	{
		swap(rand_int[t], rand_int[x]);
		down(t);
	}
}

int main()
{
	init();
	cin >> k;
	
	for(int i = N / 2 ; i >= 0; i -- )	down(i);
	for(int i = 1; i <= k; i ++ )
	{
		cout << rand_int[1] << " ";
		rand_int[1] = rand_int[s -- ];
		down(1);
	}
	return 0;
}
