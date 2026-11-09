#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n;
	while(cin>>n && n)
	{
		queue<int> a;
		for(int i=1;i<=n;i++)
			a.push(i);
		bool fir=false;
		cout << "Discarded cards:";
		while(a.size()>1)
		{
			if(fir==1)
				cout << ",";
			fir=true;
			cout << " " << a.front();
			a.pop();//将第一张牌扔掉
			a.push(a.front());//将队头的牌移到队尾
			a.pop();//删掉转移的牌 
		}
		cout << endl << "Remaining card: " << a.front() << endl;
	}
	return 0;

}
