#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int T;
	int op, h, w;
	cin >> T;
	while(T -- )
	{
		cin >> op >> h >> w;
		if(op == 1)//man
		{
			if(h < 130)	cout << "duo chi yu! ";
			else if(h == 130)	cout << "wan mei! ";
			else cout << "ni li hai! ";
			if(w < 27)	cout << "duo chi rou!" << endl;
			else if(w == 27)	cout << "wan mei!" << endl;
			else	cout << "shao chi rou!" << endl;
		}
		else
		{
			if(h < 129)	cout << "duo chi yu! ";
			else if(h == 129)	cout << "wan mei! ";
			else cout << "ni li hai! ";
			if(w < 25)	cout << "duo chi rou!" << endl;
			else if(w == 25)	cout << "wan mei!" << endl;
			else	cout << "shao chi rou!" << endl;	
		}
	}

	
	return 0;
}
