#include<iostream>
#include<algorithm>
using namespace std;
struct student
{
	int time;
	int score;	
};
bool cmp(student x,student y)
{
	return x.score>y.score;
};
int main()
{
	int n,m;
	cin >> n;
	while(n--)
	{
		int m;
		int ans=0;
		int a[12]={1,1,1,1,1,1,1,1,1,1,1,1};
		cin >> m;
		struct student stu[2000];
		for(int i=0;i<m;i++)
			cin >> stu[i].time;
		for(int i=0;i<m;i++)
			cin >> stu[i].score;	
		sort(stu,stu+m,cmp);
		for(int i=0;i<m;i++)
		{
			int flag;		//对应a[i]中的i 
			flag=stu[i].time-1;	
			if(a[flag]==1)//该时间还没有被占用 
				{
					a[flag]=0; //该时间现在被占用了 
				}
			else	//该时间已经被分更高的占用了 
				{
					int x=0;//判断前面是否还有空余时间的标志 
					for(int k=0;k<flag;k++)	//从前面的时间找 
						{
							if(a[k]==1)
								{
									a[k]=0;	
									x=1;
									break; 
								}			
						} 
					if(x==0)
						ans+=stu[i].score;
//					cout <<"redece's flag:"<< i <<endl;
				} 
		}
//		cout <<  "Time";
//	for(int i=0;i<12;i++)
//	cout <<a[i] << " ";			
//	cout << endl<<"reduce="<<ans<<endl;	
	cout << ans<<endl;
	}
	
	return 0;
}
