#include<bits/stdc++.h>
using namespace std;
vector<double>ve;
int n;
int main(void)
{
    cin>>n;
    ve.push_back(0),ve.push_back(10);
    for(int i=0;i<n;i++)
    {
        string op; cin>>op;
        if(op=="C")
        {
            double x; cin>>x;
            ve.push_back(x);
            sort(ve.begin(),ve.end());
        }else
        {
            double x; cin>>x;
            if(x==10) printf("%.5lf\n",10-ve[ve.size()-2]);//最后一个位置
            else
            {
                int index=upper_bound(ve.begin(),ve.end(),x)-ve.begin();
                printf("%.5lf\n",ve[index]-ve[index-1]);
            }
        }
    }
    return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    set<int> st;
    st.insert(0);
    st.insert(1000000);
    while(t--){
        char s[2];
        int x,y;
        scanf("%s %d.%d",s,&x,&y);
        int cur=x*100000+y;
        if(s[0]=='C'){
            st.insert(cur);
        }else{
            if(cur==1000000){
                
                int res=1000000-*prev(st.lower_bound(cur));
                printf("%d.%05d\n",res/100000,res%100000);
            }else{
                int res=*st.upper_bound(cur)-*prev(st.upper_bound(cur));
                printf("%d.%05d\n",res/100000,res%100000);
            }
        }
    }
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    set<double> s;
    s.insert(0.0);
    s.insert(10.0);
    while(t--)
    {
        char c;
        double x;
        cin >> c >> x;
        if(c=='C')
        {
            s.insert(x);
        }
        else if(c=='A')
        {
            auto it = s.lower_bound(x);
            if(x<=1e-6)
                printf("%.5f\n", *s.upper_bound(x));
            else 
                printf("%.5f\n", *it - *prev(it));
        }
    }
    return 0;
}


*/