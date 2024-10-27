/*
size() 和 length()返回的是无符号数
不能直接和int类型的值比较
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int a = 5;
    int b = -1;
    unsigned int c = b;
    cout << c << endl;
    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, maxn = -1;
vector<string> res;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
       string str;  cin >> str;
    //   cout << "str: " << str << endl;
       set<int> s;
       for(int j = 0; j < 3; j ++ )
       {
           int num; cin >> num;
           for(int k = 0; k < num; k ++ )
           {
               int x;   cin >> x;
               s.insert(x);
           }
       }
      int t = s.size();
      if(t > maxn)
       {
        //   cout << "yes" << s.size() << endl;
          res.clear();
          maxn = s.size();
          res.push_back(str);
       }
      else if(s.size() == maxn)
      {
          res.push_back(str);
      }
    }
    
    // cout << res.size() << endl;
    for(auto &ss : res)
        cout << ss << endl;
    
    return 0;
}