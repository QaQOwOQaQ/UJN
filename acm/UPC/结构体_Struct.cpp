#include<iostream>
#include<string>
using namespace std;
struct student 
{
	string name;
	int outnum;
	int innum;
	int sub;
};
int main()
{
	int n,max=0,t=0;
	struct student stu[20];
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].name>>stu[i].innum>>stu[i].outnum;
		if(stu[i].innum>stu[i].outnum)
			stu[i].sub=stu[i].innum-stu[i].outnum;
		else
			stu[i].sub=stu[i].outnum-stu[i].innum;
		if(stu[i].sub>max)
		{
			t=i;
			max=stu[i].sub;
		}	
		
	}
	cout << stu[t].name << " " << stu[t].sub;

	return 0;
}
