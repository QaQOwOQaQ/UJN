#include<iostream>
#include<string>
using namespace std;
struct student
{
	string name;
	int s1;	//chinese score
	int s2;	//math
	int s3;	//english
	int num;	//s1+s2+s3
};
int main()
{
	int n,min=0,flag=300;
	cin >> n;
	struct student stu[n];
	for(int i=0;i<n;i++)
	{
		cin >> stu[i].name;
		cin >> stu[i].s1; 	
		cin >> stu[i].s2;
		cin >> stu[i].s3;
		stu[i].num=stu[i].s1+stu[i].s2+stu[i].s3; 
		if(stu[i].num<flag)
		{
		flag=stu[i].num;
		min=i;
		}
		
	}
	cout<<stu[min].name<<" "<<stu[min].s1<<" "<<stu[min].s2<<" "<<stu[min].s3<<" "<<stu[min].num;
	return 0;
}
