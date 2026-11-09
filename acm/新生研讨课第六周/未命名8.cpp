#include<bits\stdc++.h>
using namespace std;
int main() {
    int num;
    cin >> num;
    getchar();
    while(num--)
	{
        int flag=1;
        string s;
       // int len=str.length();
        stack <char> st;
        getline(cin,s);
        for(int j=0;j<s.length();j++)
		{
            if(s[j]=='{'||s[j]=='['||s[j]=='(' )
			{
                st.push(s[j]);
            }
            if(s[j]==')'||s[j]==']'||s[j]=='}')
			{
                if(st.empty())
				{
                    flag=0;
                    break;
                }
                //char temp=mystack.top();
                if((st.top()=='('&&s[j]==')')||(st.top()=='['&&s[j]==']')||(st.top()=='{'&&s[j]=='}'))
                    st.pop();
                else{
                    flag=0;
                    break;
                }
            }
        }
        if(st.empty()&&flag==1)
            cout<<"yes"<<endl;
        else 
			cout<<"no"<<endl;
    }
    return 0;
}

