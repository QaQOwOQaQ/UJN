#include<bits/stdc++.h>

using namespace std;

struct node{
	char sex;
	string father = "-1";
};
map<string,node>people;

inline int judge(string a, string b)
{
	int i = 1, j;
	for(string A = a; !A.empty(); A = people[A].father,i ++ )
	{
		j = 1;
		for(string B = b; !B.empty(); B = people[B].father, j ++ )
		{
			if(i >= 5 && j >= 5)    return 1;//五代以内没有公共祖先
			if(A == B && (i < 5 || j < 5))    return 0; //找到了公共祖先并且辈分小与5
		}
	}
	return 1;   //不够五代且没有公共祖先
}

int main(){
	int n;  cin>>n;
	cin.sync_with_stdio(false);
	string a, b, t;  
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if(b.back() == 'n') //+sson
			people[a] = {'m',b.substr(0,b.size()-4)};
		else if(b.back()=='r')//+sdottir
			people[a] = {'f',b.substr(0,b.size()-7)};
		else people[a].sex = b.back();  //不是本地人，不需要记录父亲
	}
	int m;  cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> t >> b >> t;
		if(!people.count(a) ||  !people.count(b))			
		    printf("NA\n");
// 		if(people.find(a) == people.end() || people.find(b) == people.end())
// 			printf("NA\n");
		else if(people[a].sex == people[b].sex)
			printf("Whatever\n");
		else if(judge(a,b))
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}

