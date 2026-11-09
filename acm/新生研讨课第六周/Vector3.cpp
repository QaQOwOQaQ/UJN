#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int x,a,b;
    cin>>x;
    cin>>a;
    cin>>b;
    v.erase(v.begin()+x-1);
    v.erase(v.begin()+a-1,v.begin()+b-1);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size()-1;i++)
        cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
    return 0;
}


